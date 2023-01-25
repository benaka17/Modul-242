# Modul-242
Dies ist das Repository des Moduls 242. Es handelt sich um eine Anwendung, die Daten des ÖV abruft und auf einem M5StickC anzeigt.

<h1>Dokumentation</h1>
................................................................
<br>Version 1.3 <br>
Autor: Alexander Benak <br>
Datum: 25.01.2023 <br>
................................................................ <br>

<h2>API</h2> 
Diese API ermöglicht den Zugriff auf verschiedene Arten von Verkehrsdaten aus der Schweiz, einschliesslich Informationen über Zug-, Bus- und Schiffsfahrpläne sowie Details zu Haltestellen und Bahnhöfen. <br> <br>

Der Endpunkt <strong>/v1/stationboard</strong> wird verwendet, um Informationen über die nächsten Abfahrten oder Ankünfte an einem bestimmten Bahnhof abzurufen. Der Endpunkt benötigt zwei Parameter: <strong>station</strong> und <strong>limit</strong>.

Station: Mit diesem Parameter geben Sie den Bahnhof an, für den Sie die Abfahrts- oder Ankunftsinformationen abrufen möchten. Der Wert sollte der Name des Bahnhofs sein, z. B. "Zürich HB" oder "Bern".
<br> <br>
Limit: Mit diesem Parameter geben Sie die Anzahl der Abfahrten oder Ankünfte an, die Sie abrufen möchten. Der Höchstwert ist 100.
<br> <br>
Ich habe also folgende Daten verwendet: https://transport.opendata.ch/v1/stationboard?station=Horgen&limit=10


<h2>Vorgehensweise</h2>
Als Arduino-Entwickler kann ich die Daten aus der Transport OpenData CH API mit der ArduinoJson-Library in ein JSON-Format konvertieren. Diese Library bietet mir eine einfache und effiziente Möglichkeit, JSON-Daten in Arduino zu parsen. <br> <br>

Um zu beginnen, muss ich die ArduinoJson-Library installieren. Dazu gehe ich in die Arduino IDE und wähle Sketch > Include Library > ArduinoJson. <br>

Sobald ich die Bibliothek installiert habe, kann ich sie verwenden, um die Daten aus der API zu parsen. Zunächst muss ich mit der Klasse WiFiClient eine HTTP-Anfrage an die API stellen. Sobald ich die Antwort von der API habe, kann ich die Methode deserializeJson aus der ArduinoJson-Bibliothek verwenden, um die Daten zu parsen.
<br> <br>
Um auf die Kategorie und die Nummer zuzugreifen, kann ich den Operator [] für das JSON-Objekt verwenden. Auf die Kategorie kann durch den Aufruf von jsonDoc["connections"][0]["category"] und auf die Zahl durch den Aufruf von jsonDoc["connections"][0]["number"] zugegriffen werden. <br> (Das sind Beispielzahlen)

<h2>Fehlerbeschreibung</h2>
Leider kam das Endprodukt nicht zustande. Ich habe es nie wirklich geschafft, die gelieferten JSON's der API so zu parsen, dass ich sie auf dem M5StickC displayen kann.

<h2>Funktionalität</h2>
Das Programm sollte wie folgt vorgehen: <br>
&nbsp;&nbsp; 1. Sich mit dem WLAN verbinden <br>
&nbsp;&nbsp; 2. Die Daten der API abrufen <br>
&nbsp;&nbsp; 3. Das JSON parsen <br>
&nbsp;&nbsp; 4. Auf die Kategorie und Nummer zugreifen <br>
&nbsp;&nbsp; 5. Auf dem M5StickC displayen <br>

Mein Code konnte zwar auf die Daten zugreifen, jedoch habe ich es nicht geschafft auf die entsprechenden Elemente im JSON zuzugreifen.

<h2>Benutztes Gerät</h2>
<img src="https://dealpro.ch/wp-content/uploads/2021/06/M5Stack-M5StickC-Plus-ESP32-pico-3.jpg" width=150>
Die Arduino-Plattform in Kombination mit dem M5StickC ermöglicht eine breite Palette kreativer Projekte und Anwendungen. Der M5StickC ist ein kompaktes Entwicklungsboard, das einen ESP32-Mikrocontroller, ein Farbdisplay und mehrere Sensoren und Tasten integriert hat. Das macht ihn zu einem leistungsstarken Werkzeug für die Entwicklung von Projekten wie Smartwatches, Wetterstationen, Hausautomatisierungssystemen und vielem mehr. Mit der Arduino-Programmiersprache und der grossen Gemeinschaft von Entwicklern sind die Möglichkeiten endlos. Sie können auch andere Sensoren und Aktoren an den M5StickC anschließen, um seine Möglichkeiten noch weiter zu erweitern.

