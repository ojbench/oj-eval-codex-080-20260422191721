# Problem 080 - Vexoben 的摸鱼骑士

**ACMOJ Problem ID**: 1760

## Table of Contents

- [Problem 080 - Vexoben 的摸鱼骑士](#problem-080-vexoben-的摸鱼骑士)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **1760. Vexoben 的摸鱼骑士** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/080/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

在很遥远的世界里，有一个Vexoben的王国，Vexoben是王国的国王，他有一群很爱摸鱼的大臣，总共有 $n$ 条。

有一天，他想要举办一场宴会。宴会中，所有被邀请的大臣会在圆桌上做成一圈。但他发现，有些大臣相互撞见过对方摸鱼，如果把他们安排在同一场宴会的相邻座位，他们就会在一起摸鱼，这是Vexoben不允许的。经过细致调查，Vexoben发现，几乎所有大臣都相互撞见过对方摸鱼，没有相互撞见过的只有 $m$ 对

另外，没有互相见证对方摸鱼的两个大臣有可能会组建摸鱼互助小组。为了阻止他们两两形成摸鱼互助小组，Vexoben决定只宴请奇数位（不能是1位）大臣。

但Vexoben意识到，为了满足这两个条件，有些大臣可能永远无法被宴请到，你能帮Vexoben算一下这样的人有多少吗？

### Input Format

第一行两个整数$n$和$m$

之后$m$行，每行两个整数$x，y$表示一组没见证过对方摸鱼的大臣

### Output Format

一行一个整数表示答案

### Samples

#### Sample 1

**Input:**
```
5 5
1 2
1 3
2 3
2 4
3 5
```

**Output:**
```
2
```

### Data Constraints

$N\le100000,M\le300000$

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 5000 ms
- **Memory Limit (per test case)**: 256 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/080/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
