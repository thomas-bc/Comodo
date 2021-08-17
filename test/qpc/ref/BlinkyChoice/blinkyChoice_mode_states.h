/* 
 * This code was generated by Comodo (https://github.com/Open-MBEE/Comodo) 
 * using the QPC-C Target Platform
 *
 * - Generated Class (Comodo Module):
 *      blinkyChoice
 *
 * - Generated State Machine (Comodo Component):
 *      mode
 * 
 */


 

#ifndef BLINKYCHOICE_MODE_STATES_H_
#define BLINKYCHOICE_MODE_STATES_H_

/**
 * Enumerate all the states that the state machine may be in at any given time.
 * An addition to the Samek pattern, state enums facilitate convenient
 * query of current state a State Machine is in at a given moment.
 */
typedef enum blinkyChoice_mode_state {
    BLINKYCHOICE_MODE__TOP__, /* Top = 0 */
    BLINKYCHOICE_MODE_FINALSTATE0,
    BLINKYCHOICE_MODE_OFF,
    BLINKYCHOICE_MODE_ON,
    BLINKYCHOICE_MODE_UNNAMEDSTATE0,

} blinkyChoice_mode_state;

#endif /* BLINKYCHOICE_MODE_STATES_H_ */
