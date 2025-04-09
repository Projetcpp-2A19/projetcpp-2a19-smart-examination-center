import QtQuick
import QtQuick.Controls
import QtLocation
import QtPositioning

Rectangle {
    width: 2000
    height: 1500

    property var currentMarker: null

    Plugin {
        id: mapPlugin
        name: "osm"
        PluginParameter {
            name: "osm.mapping.custom.host"
            value: "https://tile.openstreetmap.org/"
        }
        PluginParameter {
            name: "osm.mapping.providersrepository.disabled"
            value: "true"
        }

        Component.onCompleted: console.log("Plugin status:", availableServiceProviders)
    }

    ListModel {
        id: validResultsModel
    }

    GeocodeModel {
        id: geocodeModel
        plugin: mapPlugin
        autoUpdate: false

        onStatusChanged: {
            console.log("Geocode status:", status)
            if (status === GeocodeModel.Error) {
                console.log("Erreur de géocodage:", errorString)
            }
        }

        onLocationsChanged: {
            console.log("Found locations:", count)
            validResultsModel.clear()
            for (var i = 0; i < count; i++) {
                var item = get(i)
                if (item.coordinate && item.address && item.address.text.length > 0) {
                    validResultsModel.append({
                        text: item.address.text,
                        coordinate: item.coordinate
                    })
                }
            }
        }
    }

    Column {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.margins: 10
        spacing: 5
        width: parent.width * 0.4
        z: 1

        TextField {
            id: searchField
            width: parent.width
            placeholderText: "Entrez une adresse (ex: Tunis, Ariana)"
            onAccepted: performSearch()
        }

        Button {
            text: "Rechercher"
            width: parent.width
            onClicked: performSearch()
        }

        ListView {
            width: parent.width
            height: 150
            model: validResultsModel
            clip: true

            delegate: Button {
                width: parent.width
                text: model.text
                onClicked: {
                    console.log("Coordinate clicked:", model.coordinate)
                    mapView.center = model.coordinate
                    mapView.zoomLevel = 15

                    if (currentMarker) {
                        mapView.removeMapItem(currentMarker)
                        currentMarker = null
                    }

                    // Vérifier la validité des coordonnées
                    if (model.coordinate.latitude !== 0 && model.coordinate.longitude !== 0) {
                        currentMarker = markerComponent.createObject(mapView, {
                            coordinate: model.coordinate
                        })
                        console.log("Marker created:", currentMarker)
                        mapView.addMapItem(currentMarker)
                    } else {
                        console.log("Invalid coordinates")
                    }
                }
            }

            ScrollBar.vertical: ScrollBar {}
        }
    }
    Map {
        id: mapView
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(36.8065, 10.1815)
        zoomLevel: 12

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.AllButtons

            function handleWheel(wheel) {
                if (wheel.angleDelta.y > 0)
                    mapView.zoomLevel = Math.min(mapView.zoomLevel + 0.5, 20)
                else
                    mapView.zoomLevel = Math.max(mapView.zoomLevel - 0.5, 2)
            }

            onWheel: handleWheel(wheel)
            drag.target: mapView
        }

        Rectangle {
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 5
            width: attributionText.width + 10
            height: attributionText.height + 5
            color: "white"
            opacity: 0.7

            Text {
                id: attributionText
                anchors.centerIn: parent
                text: "© OpenStreetMap contributors"
                font.pixelSize: 12
                color: "black"
            }
        }
    }

    Component {
        id: markerComponent
        MapQuickItem {
            anchorPoint.x: 12
            anchorPoint.y: 24
            coordinate: QtPositioning.coordinate(0, 0)
            sourceItem: Image {
                source: "qrc:/img/marker.png"
                width: 24
                height: 24
                onStatusChanged: {
                    if (status === Image.Error) {
                        console.log("Image failed to load:", source)
                    }
                }
            }
        }
    }

    function performSearch() {
        console.log("Recherche de :", searchField.text)
        if (searchField.text.length > 2) {
            geocodeModel.query = searchField.text
            geocodeModel.update()
        } else {
            console.log("Requête trop courte")
        }
    }

    Component.onCompleted: {
        console.log("Plugins disponibles:", QtLocation.availableServiceProviders())
        console.log("OSM plugin prêt:", mapPlugin.ready)
    }
}
