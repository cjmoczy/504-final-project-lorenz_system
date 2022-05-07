# 504-final-project-lorenz_system
Final project for PHY 504 investigating the Lorenz system and its parameters.


This repository was created as a final project for PHY 504 which explores the Lorenz system. The Lorenz system is a system ordinary differential equations known for having chaotic solutions for specifc intial conditions and parameter values. The equations and further description of the Lorenz system can be found [https://en.wikipedia.org/wiki/Lorenz_system](https://en.wikipedia.org/wiki/Lorenz_system).


## Program Purpose

The purpose of this program uses an integrator to explore parameter space of the lorenz system. By varying the parameters in the problem, one can look at how two initially-close solutions compare at longer time. The integrator uses the 2nd order Runge-Kutta method, which is part of a family of iterative methods used to approximate solutions of Ordinary Differential Equations. Given some set of inital conditions, the integrator evaluates values at specific points in intervals of the specified time step. In addition, after each of iteration, values are output to the terminal, allowing for the capacity to export the data with a file extension such as *.dat or *.txt.


## Assumptions

User has gnuplot installed for use in the terminal.

## Usage

Located in the lorenz.cpp file, the following block of code below is the primary space to alter 5 parameter values: tmax, dt, sigma, beta, and rho.

```c++
int main() {

    double tmax = 35;
    double dt = 0.01;
    double sigma = 10;    
    double beta = 8.0 / 3.0;
    double rho = 28;

    auto lorenz_history = integrate_rk2(sigma, beta, rho, tmax, dt);
    write_history(lorenz_history);

}
```
By altering these 5 parameter values, one can begin to understand how a small change in these values results in chaotic behavior. The default values are tmax = 35, dt = 0.01, sigma = 10, beta = 8.0 / 3.0, and rho = 28. After altering these values and saving, the following code should be run in the terminal. 

```
$ make
```
Once the executable has been made, the following executable can be ran in the terminal.
```
$ ./lorenz
```
After running this in the terminal, one should see data displayed in the terminal.
    ```md
    ![alt text](assets/images/data.png)
    ```
Following the step of displaying data, one can export the data into a .dat file. This is useful when plotting the data using gnuplot. 

```
$ ./lorenz > lorenz.dat
```
The data will be exported as lorenz.dat. In the terminal, one can now run the command to launch gnuplot.

```
$ gnuplot
```
The terminal type will now change to to 'qt'. Simply run the following command in the new terminal type to display an a graph of the chaotic behavior of the lorenz system.
```
gnuplot> splot "lorenz.dat" u 2:3:4 w l
```
    ```md
    ![alt text](assets/images/data.png)
    ```


## Credits

List your collaborators, if any, with links to their GitHub profiles.

If you used any third-party assets that require attribution, list the creators with links to their primary web presence in this section.

If you followed tutorials, include links to those here as well.

## License

The last section of a high-quality README file is the license. This lets other developers know what they can and cannot do with your project. If you need help choosing a license, refer to [https://choosealicense.com/](https://choosealicense.com/).

---

🏆 The previous sections are the bare minimum, and your project will ultimately determine the content of this document. You might also want to consider adding the following sections.
- [Installation](#installation)
- [Usage](#usage)
- [Credits](#credits)
- [License](#license)
-- something
## Features

If your project has a lot of features, list them here.

## How to Contribute

If you created an application or package and would like other developers to contribute it, you can include guidelines for how to do so. The [Contributor Covenant](https://www.contributor-covenant.org/) is an industry standard, but you can always write your own if you'd prefer.

## Tests

Go the extra mile and write tests for your application. Then provide examples on how to run them here.
