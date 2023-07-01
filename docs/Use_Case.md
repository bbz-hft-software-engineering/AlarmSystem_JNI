# Use Case: Alarm System 

## Actors
- User
- Alarm System

## Preconditions
- The Alarm System is installed and powered on.
- User has access to the Alarm System controls.
- Door sensor is installed and functioning.

## Main Flow
1. User approaches the Alarm System control panel.
2. User presses the red button to activate the Alarm System.
3. Alarm System transitions from Inaktiv state to Idle state.
4. User closes the door, indicating readiness for the Alarm System.
5. Alarm System transitions from Idle state to Activ state.
6. User presses the red button or opens the Door to deactivate the Alarm System.
7. Alarm System transitions from Aktiv state to Code Input state.
8. User enters the system PIN code.
9. If the correct PIN code is entered, Alarm System transitions from Code Input state to Inaktiv state.
10. If the wrong PIN code is entered or 30 seconds elapse, Alarm System transitions from Code Input state to Alarm state.
11. Alarm System activates the alarm, triggering a Alarm on the System and activating the Siren.
12. Use case ends.

## Postconditions
- The Alarm System is in the Inaktiv state or Alarm state based on the outcome of the user's interaction.