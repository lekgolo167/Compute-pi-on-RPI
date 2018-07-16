# Compute-pi-on-RPI
Compute pi on the raspberry pi up to 1000 digits and displays the result in the shape of a pi.
Uses all threads on the pi.

# Make a build directory cd to the build directory then run these commands to build
cmake ..
make

# To run (accepts no arguments and defaults to 1000 or you can enter a number 1 to INT_MAX)
./ComputePi or ./ComputePi 2000
