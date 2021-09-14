
--------------------------------------------------------
To compile program:
make driver

To clean:
make clean

gitHub: https://github.com/harisbihorac/4760p1
--------------------------------------------------------
Methods of invocation:
	./driver -- prints messages to output file messages.log
	./driver -h -- prints usage message
	./driver -t sec -- prints messages on average every sec seconds
	./driver [file name] -- prints messages to specified output file name
--------------------------------------------------------
Problems I encountered:
1. I may have not used perror enough, but I used it where I thought necessary
2. When encountering a fatal message, I believe that the instructions stated that you should print it to a different output file named savelog, so that's what I did
3. The program may create an additional message at the end, not sure why its doing that
4. I'm not sure if I implemented the -t sec option correctly...it was a bit confusing
5. I went a couple days without commiting to git repo because I forgot
---------------------------------------------------------
