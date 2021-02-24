#include <stdio.h>
#include <stdint.h>
#include <cstring>

namespace GCMD{
    typedef enum{
        READ,
        ERROR,
        DONE,
        WRITE
    }GCMDStates;
}

typedef enum{
    Idle,
    EPIdle,
    EPWaitforInit,
    EPCommandMode,
    UIJSONProcessJSON,
    UIJSONDone
}EPState;

typedef enum {
    EPError,
    EPSuccess
}EPReturn;

EPReturn runJSONCommand(const char* jsontext, uint8_t const * pbOutput, uint32_t &cbOutput){
    // Copy Command
    static char szInput[1024];
    static uint32_t cbInput = 0;
    while (jsontext[cbInput]!='\0') cbInput++;
    memcpy(szInput, jsontext, cbInput);
    
    cbOutput = 4;
    const uint8_t output[] = {(uint8_t)1,(uint8_t)3,(uint8_t)6,(uint8_t)4};
    pbOutput = output;
    EPState state = Idle;

    while(state!=Idle){
        switch (state){
            // inits the MCU
            case UIJSONProcessJSON:
                // switch(oslex.StreamOS(szInput, cbInput))
                // {
                //     case GCMD::READ:
                //         // This should never happen
                //         break;

                //     case GCMD::ERROR:
                //         // Wrong Command
                //         Serial.println("GCMD:Error");
                //         return EPError;

                //     case GCMD::DONE:
                //         state = UIJSONDone;
                //         break;
                
                //     case GCMD::WRITE:
                //         cbOutput = oslex.cbOutput;
                //         pbOutput = oslex.pbOutput;
                //         state = UIJSONProcessJSON;
                        // break;

                    // continue
                    // default:
                    //     break;
                // }
                break;

            case UIJSONDone:
                // // Unlock all of the buffers
                // for(int32_t i=0; i<oslex.cOData; i++)
                // {
                //     if(oslex.odata[i].pLockState != NULL && *oslex.odata[i].pLockState == LOCKOutput)
                //     {
                //         *oslex.odata[i].pLockState = LOCKAvailable;
                //     }
                // }

                // // we are no longer parsing JSON
                // oslex.Init(OSPAR::ICDEnd);
                // state = Idle; // The End
                break;

            default:
                break;
        }
    }
    return EPSuccess;
}