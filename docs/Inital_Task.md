# Softwareentwicklung
LN - 3, Photon Projekt, Manuel Geissmann | LN3.docx
Leistungsnachweis 3 Beschreibung – Photon Projekt

# Einführung
Als dritten Leistungsnachweis gilt die Umsetzung eines kleinen Projekts auf dem Photon.

# Aufgabenstellung
Ziel des Projekts ist es eine Alarmanlage zur Verbesserung der Heimsicherheit zu entwickeln. Das
System soll auf der Particle Photon Inventor’s Kit Hardware aufbauen. Durch den Einsatz
verschiedener Sensoren und Aktoren soll die Alarmanlage bei unerwünschtem Eindringen ins
Eigenheim Alarm schlagen

# Produkt Anforderungen
- Die Alarmanlage wird durch den Aktivierungsknopf aktiviert.
- Nach der Aktivierung erklingt ein kurzer Ton.
- Nach dem Öffnen der Tür leuchtet eine LED gelb und es erklingt ein Ton für 30 Sekunden.
- Mit der richtigen Tastenkombination der zwei Knöpfe kann der Alarm innerhalb von 30 Sekunden abgeschaltet werden.
- Die Tastenkombination lautet zweimal den linken Knopf drücken und einmal den rechten Knopf drücken.
- Wird die richtige Kombination nach 30 Sekunden nicht eingegeben leuchtet eine rote Kontrollleuchte.
- Wird die richtige Kombination innerhalb von 30 Sekunden eingegeben leuchtet eine grüne LED
- Wird die richtige Tastenkombination eingegeben wird dies durch zwei kurze Töne bestätigt
- Wurde die richtige Kombination eingegeben resp. die grüne LED leuchtet, kann die Alarmanlage durch den Aktivierungsknopf wieder aktiviert werden.

# HW Aufbau
- Türöffnungssensor
- Drei Knöpfe «links», «rechts», «Aktivierungsknopf»
- Grüne, orange, rote LED
- Lautsprecher

# Hilfe
##  LED
https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-for-photon-experiment-guide/experiment-1-hello-world-blink-an-led

##  Buttons
https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-for-photon-experiment-guide/experiment-2-with-the-touch-of-a-buttonSoftwareentwicklung

## Lautsprecher
https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-for-photon-experiment-guide/experiment-5- music-time

## Display
https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-for-photon-experiment-guide/experiment-11-oled-apps---weather--clock

# Optional
- Anstatt den LEDs soll ein Display den Status der Alarmanlage ausgeben
- Status:
  - Aktiv
  - Inaktiv
  - Alarm
  - Code Eingabe
- Um Strom zu sparen, soll nach 2 Minuten Inaktivität das Display ausschalten
- Durch Drücken eines beliebigen Knopfes kann das Display wieder aktiviert werden.

# Artefakte
Folgende Artefakte sind abzugeben und werden bewertet:
| Artefakt | Beschreibung | Abgabedatum |
|----------|--------------|-------------|
| Source-Code | Source-Code des Projekt | 30.06.2023 |
| Design Artefakte | Sequenzdiagramm, Erklärung Idee, | 30.06.2023 |
| Use. Case | Anforderungen, nicht funktionale Anforderungen, Ablauf use-case, Fehlerfall | 30.06.2023 |
| Test-Protokoll | Testkonzept, sowie Protokoll der durchgeführten Tests | 30.06.2023 |