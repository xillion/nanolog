# pt-logger-l433-test-fw

Dev commands
dev -test
dev -id
dev -info
dev -gain
dev -vref
dev -vfb
dev -term
dev -adc
dev -vbat
dev -time (-e/-h) <time_in_sec>/<time_string>
dev -timer (-run/-stop)
dev -alarm (-e/-h) 
dev -pass -old <un_old_pass> -new <a_new_pass>
dev -dfu -p <a_pass>
dev -save
dev -erase (-i/-meas/-conf/-log/-all)
dev -call "list of values"
dev -file
dev -press
dev -mem -p <page_number>
dev -conf

Project commands
pro -info
pro -mode
pro -stime (-e/-h) <time_in_sec>/<time_string>
pro -etime (-e/-h) <time_in_sec>/<time_string>
pro -chunk (-i/-s/-n)
pro -file
pro -int


errors

0 - no error
1 - wrong parameters
2 - wrong value
3 - not implemented
4 - busy
5 - wrong password
6 - passwords mismatch
7 - password too short
8 - password too long
9 - wrong password's symbols 
10 - chunk size out of range
11 - chunk number out of range
12 - no data
13 - 
14 - 

    ERROR_OK = 0,
    ERROR_UNKNOWN_CMD,
    ERROR_INVALID_CMD,
    ERROR_INVALID_KEY,
    ERROR_INVALID_VALUE,
    ERROR_OUT_OF_RANGE,
    ERROR_PWD_SHORT,
    ERROR_PWD_LONG,
    ERROR_PWD_SYMBOLS,
    ERROR_PWD_IMCORRECT,
    ERROR_PWD_MISMATCH,
    ERROR_MEMORY,
    ERROR_TIMEOUT,
    ERROR_BUSY,
    ERROR_NODATA,
    ERROR_NOT_IMPLEMENTED,
    ERROR_UNKNOWN,