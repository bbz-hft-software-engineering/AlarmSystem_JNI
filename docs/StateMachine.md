```mermaid
stateDiagram-v2
    classDef Error fill:#f00,color:white,font-weight:bold,stroke-width:2px,stroke:yellow
    classDef Warning fill:Orange,color:white,font-weight:bold,stroke-width:2px,stroke:white
    classDef Information fill:Blue,color:white,font-weight:bold,stroke-width:2px,stroke:white

    [*] --> SM_Inaktiv
    SM_Inaktiv --> SM_Idle: Red Button
    SM_Idle --> SM_Aktiv: Door closed
    SM_Aktiv --> SM_Code: Red Button
    SM_Aktiv --> SM_Code: Door opend
    SM_Code --> SM_Inaktiv: Correct Passcode
    SM_Code --> SM_Alarm: Wrong Passcode
    SM_Code --> SM_Alarm: 30 Sec
    SM_Alarm --> [*]

    class SM_Alarm Error
    class SM_Aktiv Warning
    class SM_Code Information
    ```

