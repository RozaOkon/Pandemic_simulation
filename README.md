# Pandemic_symulation
The program is a simplified pandemic simulator which creates an animation showing simulated city's citizens movement and health dependence on time.

It creates points - each of them symbolize single person with its own two-dimentional velocity and color which shows health - green color means a health person, red - an infected person and blue color - a convalescent. Infected people infect health people who are close enough. The goal of the simulation is to create a visualization citizens health after given time and other initial conditions.

The program plots single frames for every time step. If merging them into an animation does not work, you should use a system command: convert -delay 0.01 -loop 0 frame*.png animation.gif

If you want to read parameters from a file, it should be named:  "input_configuration.txt" and it should have an appropriate formatting, as in the file with such name in repository.

Initial parameters can be set by drawing, reading from a file named 'input_configuration.txt' or running a test version. The "city" of simulation have its parameters which can be modified by command line in any order using following names:

'--nIter' means the number of time iterations (default 50),
'--dt' means time step between iterations (default 0.02 s),
'--boxSize' means city size (default 1 m),
'--recoveryTime' means time needed for recovery (default 0.7 s)
'--input' (values: 'test', 'random', 'file') defines a way to input initial parameters
'--nPeople' means number of citizens in the simulation, only for random parameters input
'--output' (values: 'true', 'false') defines if finish state should be written to a file
'--doFrame' (values: 'true', 'false') defines if the animation should be made.

Command to run program with default parameters: ./a.out

Exemplary command to run program with parameters control:
./a.out --nIter 30 --dt 0.02 --nPeople 50 --input random --boxSize 1 --recoveryTime 1.2
For that way of running program, if some parameter is not entered, the program takes a default value and display the communicat on the screen.

Compilation command: g++ *.cpp -DWITHOUT_NUMPY
