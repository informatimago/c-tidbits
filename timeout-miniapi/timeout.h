#ifndef timeout_h
#define timeout_h

#define TIMEOUT_TIMEOUT   33
#define TIMEOUT_COMPLETED 42
     int schedule_with_timeout(void (* func)(void), int delay_in_seconds);
     int timeout_begin(unsigned int seconds);
     int timeout_end(void);

#define WITH_TIMEOUT(seconds)                                           \
     do{                                                                \
         if(0==timeout_begin(seconds)){

#define WHEN_TIMEOUT                                                    \
	 }                                                              \
         if(timeout_end()){

#define WHEN_EARLY_COMPLETION                                           \
         }else{

#define END_TIMEOUT                                                     \
         }								\
    }while(0)

#endif
