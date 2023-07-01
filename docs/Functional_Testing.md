Test Cases for the Alarm System:

| # | Test Case | Description | Procedure | Expected Result | Result |
|---|-----------|-------------|-----------|-----------------|--------|
| 1 | System Activation | Verify that the system can be successfully activated using the red Button. | 1. Press the activation button. | The system transitions from the inactive state to the idle state. | PASS |
| 2 | Door Closure Detection | Verify that the system detects the closure of the door and transitions to the active state. | 1. Close the door. | The system transitions from the idle state to the active state. | PASS |
| 3 | Incorrect PIN Entry | Verify that the system responds appropriately when an incorrect PIN code is entered. | 1. Enter an incorrect PIN code. | The system triggers the alarm and enters the alarm state. | PASS |
| 4 | Correct PIN Entry | Verify that the system responds appropriately when the correct PIN code is entered within the time limit. | 1. Enter the correct PIN code. | The system transitions from the active state to the inactive state. | PASS |
| 5 | Alarm Trigger | Verify that the system triggers the alarm when unauthorized access is detected. | 1. Open the door while the system is in the active state. | The system triggers the alarm and enters the alarm state. | PASS |
| 6 | Alarm Reset | Verify that the alarm can be manually reset by authorized personnel. | 1. Access the reset function using appropriate authorization. 2. Perform the reset process. | The alarm is disabled, and the system returns to the inactive state. |   PASS |