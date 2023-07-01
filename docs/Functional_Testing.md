# Test Protocol

Test Date: 01.07.2023
Tester : Jan Nägeli 
Type of Test: Manual Functional Testing

##Test Cases for the Alarm System:

| # | Test Case | Description | Procedure | Expected Result | Result |
|---|-----------|-------------|-----------|-----------------|--------|
| 1 | System Inactive | Inactive State Display Message | Start up the System | The Display shows the Inactivation State Message | PASS |
| 2 | System Activation | The system can be successfully activated using the activation Button. | Press the red button. | The system transitions to the idle state. | PASS |
| 3 | System Activation | Other Inputs on the System | Test all other Inputs | Any other Input than the Red Button is ignored | PASS |
| 4 | System Activation | Idle State Display Message | System is in Idle State | The Display shows the Idle State Message | PASS |
| 5 | Door Closure Detection | The system detects the closure of the door and transitions to the active state. | Close the door. | The system transitions to the active state. | PASS |
| 6 | Door Closure Detection | Other Inputs on the System | Test all other Inputs | Any other Input than the closure of the Door is ignored | PASS |
| 7 | System Active | Active State Display Message | System is in Active State | The Display shows the Active State Message | PASS |
| 8 | Door Closure Detection | The system detects the opening of the door and transitions to the Code Entry state. | Open the door. | The system transitions to the Code Entry state. | PASS |
| 9 | Correct PIN Entry | The system responds appropriately when the correct PIN code is entered within the time limit. | Enter the correct PIN code. | The system transitions to the inactive state. | PASS |
| 10 | Incorrect PIN Entry | The system responds appropriately when an incorrect PIN code is entered. | Enter an incorrect PIN code. | The system enters the alarm state. | PASS |
| 11 | Alarm Delay | The System responds appropriately when no Code is entered within the time limit | Wait for 30 second | The system enters the alarm state. | PASS |
| 12 | Display Sleep | The Display turns off after a specified Delay | Wait for 2 min | The Display turns off | PASS |
| 13 | Display Sleep | The Display turns on if any Input is made | Any Input | The Display turns on | PASS |
| 14 | Display Sleep | The System transition from the Active to the Code entry State even if the Display is off | Open the Door in the Active State while Display is off | The System transitions to the Code Entry Stage | PASS |
| 15 | Alarm Reset | Verify that the alarm can be manually reset by authorized personnel. | Perform a System Reset | The alarm is disabled, and the system returns to the inactive state. | PASS |