/*
 * Generic utilities
 */

#define CREATE(result, type, number)  do {\
        if ((number) * sizeof(type) <= 0) {       \
                sprintf(buf, "SYSERR: Zero bytes or less requested at %s:%d.", __FILE__, __LINE__);      \
                Serial.println(buf);      \
        }      \
        if (!((result) = (type *) calloc ((number), sizeof(type))))     \
                { perror("SYSERR: malloc failure"); abort(); } } while(0)
