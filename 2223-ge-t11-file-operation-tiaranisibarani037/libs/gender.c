#include "gender.h"

/**
 * @brief Define the complete function definition here. Be sure to enlist the prototype of each function
 * defined here in the corresponding header file.
 *
 */

char *gender_to_text(enum gender_t _gender){
    
    switch(_gender)
    {
        case GENDER_MALE:
        return "male";
        break;
        case GENDER_FEMALE:
        return "female";
        break;
        default:
        return "unknown";

    }
}