#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include TIMEOUTLIB_H

int block = 0;
// Example function to be called in the new thread
void example_function() {
    printf("Hello from the example function!\n%s\n",
           (block?"Will block.":"Returns now."));
    if (block) while(1) sleep(1);
}

    
int main(int argc,char** argv) {
    int result;
    if((argc>1)&&(0==strcmp(argv[1],"--block"))){
        block=1;
    }
    result = schedule_with_timeout(example_function, 5);
    printf("Result: %d\n", result);

    WITH_TIMEOUT(10){
        example_function();
	}
	WHEN_TIMEOUT{
		/* success */
        printf("Result: example_function() doesn't return\n");
	}
	WHEN_EARLY_COMPLETION{
        printf("Result: example_function() returned early!\n");
	}
    END_TIMEOUT;


    return 0;
}


