import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 1400
    height: 900
    title: "AI Forge Studio - RTX 50-Series Edition"
    
    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#0A0A0F" }
            GradientStop { position: 1.0; color: "#1A1A2E" }
        }
    }
    
    Column {
        anchors.fill: parent
        anchors.margins: 40
        spacing: 30
        
        // Header
        Row {
            width: parent.width
            spacing: 20
            
            Column {
                spacing: 10
                Text {
                    text: "AI FORGE STUDIO"
                    font.pixelSize: 48
                    font.bold: true
                    color: "#00FFFF"
                    style: Text.Outline
                    styleColor: "#AA00FF"
                }
                Text {
                    text: "RTX 50-Series Edition"
                    font.pixelSize: 24
                    color: "#FFFFFF"
                    opacity: 0.7
                }
            }
            
            Item { Layout.fillWidth: true }
            
            Rectangle {
                width: 200
                height: 80
                color: Qt.rgba(0.0, 1.0, 0.0, 0.1)
                radius: 10
                border.color: "#00FF00"
                border.width: 2
                
                Column {
                    anchors.centerIn: parent
                    spacing: 5
                    Text {
                        text: "● SYSTEM READY"
                        font.pixelSize: 16
                        font.bold: true
                        color: "#00FF00"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                    Text {
                        text: gpuMonitor.isNVMLAvailable ? "NVML Active" : "Mock Mode"
                        font.pixelSize: 12
                        color: "#FFFFFF"
                        opacity: 0.7
                        anchors.horizontalCenter: parent.horizontalCenter
                    }
                }
            }
        }
        
        // GPU Stats
        Rectangle {
            width: parent.width
            height: 350
            color: Qt.rgba(0.1, 0.1, 0.2, 0.8)
            radius: 15
            border.color: "#00FFFF"
            border.width: 2
            
            Column {
                anchors.fill: parent
                anchors.margins: 30
                spacing: 20
                
                Row {
                    width: parent.width
                    spacing: 20
                    Text {
                        text: "🎮 " + gpuMonitor.gpuName
                        font.pixelSize: 24
                        font.bold: true
                        color: "#00FFFF"
                    }
                    Text {
                        text: "Driver: " + gpuMonitor.driverVersion
                        font.pixelSize: 14
                        color: "#FFFFFF"
                        opacity: 0.7
                        anchors.verticalCenter: parent.verticalCenter
                    }
                }
                
                GridLayout {
                    width: parent.width
                    columns: 3
                    rowSpacing: 20
                    columnSpacing: 30
                    
                    // Temperature
                    Rectangle {
                        Layout.fillWidth: true
                        height: 100
                        color: Qt.rgba(1.0, 0.3, 0.0, 0.1)
                        radius: 10
                        border.color: "#FF6600"
                        border.width: 2
                        Column {
                            anchors.centerIn: parent
                            spacing: 5
                            Text {
                                text: "TEMP"
                                font.pixelSize: 12
                                color: "#FFFFFF"
                                opacity: 0.7
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
                            Text {
                                text: gpuMonitor.temperature.toFixed(1) + "°C"
                                font.pixelSize: 28
                                font.bold: true
                                color: "#FF6600"
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
                        }
                    }
                    
                    // Utilization
                    Rectangle {
                        Layout.fillWidth: true
                        height: 100
                        color: Qt.rgba(0.0, 1.0, 1.0, 0.1)
                        radius: 10
                        border.color: "#00FFFF"
                        border.width: 2
                        Column {
                            anchors.centerIn: parent
                            spacing: 5
                            Text {
                                text: "GPU"
                                font.pixelSize: 12
                                color: "#FFFFFF"
                                opacity: 0.7
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
                            Text {
                                text: gpuMonitor.utilization.toFixed(0) + "%"
                                font.pixelSize: 28
                                font.bold: true
                                color: "#00FFFF"
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
                        }
                    }
                    
                    // Memory
                    Rectangle {
                        Layout.fillWidth: true
                        height: 100
                        color: Qt.rgba(0.7, 0.0, 1.0, 0.1)
                        radius: 10
                        border.color: "#AA00FF"
                        border.width: 2
                        Column {
                            anchors.centerIn: parent
                            spacing: 5
                            Text {
                                text: "VRAM"
                                font.pixelSize: 12
                                color: "#FFFFFF"
                                opacity: 0.7
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
                            Text {
                                text: (gpuMonitor.memoryUsed/1024).toFixed(1) + " GB"
                                font.pixelSize: 28
                                font.bold: true
                                color: "#AA00FF"
                                anchors.horizontalCenter: parent.horizontalCenter
                            }
                        }
                    }
                }
            }
        }
        
        // Features
        Rectangle {
            width: parent.width
            height: 200
            color: Qt.rgba(0.1, 0.1, 0.2, 0.8)
            radius: 15
            border.color: "#00FFFF"
            border.width: 2
            
            Column {
                anchors.centerIn: parent
                spacing: 15
                Text {
                    text: "AVAILABLE FEATURES"
                    font.pixelSize: 18
                    color: "#00FFFF"
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                Row {
                    spacing: 40
                    anchors.horizontalCenter: parent.horizontalCenter
                    Column {
                        spacing: 8
                        Text { text: "✓ Real-time GPU Monitoring"; font.pixelSize: 14; color: "#FFFFFF" }
                        Text { text: "✓ Multi-Model AI Support"; font.pixelSize: 14; color: "#FFFFFF" }
                    }
                    Column {
                        spacing: 8
                        Text { text: "✓ Vulkan Rendering"; font.pixelSize: 14; color: "#FFFFFF" }
                        Text { text: "✓ Ollama Integration"; font.pixelSize: 14; color: "#00FF00" }
                    }
                }
            }
        }
    }
}
