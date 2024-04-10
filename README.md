# Monty Hall Simulator Bonus

This takes 3 arguments num_doors, num_doors_opened_by_host and outputs the winning percentage based on two strategies i.e sticking to the choice taken and switching the doors.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Explanation](#explanation)

## Installation

Download the project  
Basic c++ setup

## Usage

g++ main.cpp -o output  
Example for running output file  
./output 10 6

## Explanation

**Sticking:**  
Probability that selected door will be the one with the prize if we stick is 1 / num_doors  

**Switching:**  
Probability that switching door will be the one with the prize is ((n - 1) / n) * (1 / n - p - 1) where n = num_doors and p = num_doors_opened_by_host. This is because firstly there will be prize behind the door now if we select the door with the prize in switching case it is useless hence to select the door without a prize the probability is ((n - 1) / n). Then p doors are revealed in which there is no prize. Hence by switching to get the correct door we should there are 1 out of n - p - 1 unopened doors. At last we will get the probability as ((n - 1) / n) * (1 / n - p - 1).  
