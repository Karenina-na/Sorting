# 🎉 Sorting-Algorithm-Interface-Framework

The Sorting Algorithm Interface Framework project constitutes the capstone assignment of the Algorithm Design and Integration Laboratory course at Northwestern Polytechnical University.

## 📚 Introduction

The role of sorting algorithms in engineering is of paramount importance. Therefore, the selection, utilization, and design of sorting algorithms in various engineering applications significantly influence task performance.

This project encompasses the implementation, quantitative comparison, and evaluation of the performance of commonly employed sorting algorithms. It entails an analysis of their applicable conditions

The project has realized the following sorting algorithms:

- insertion sort
- bubble sort
- selection sort
- shell sort
- quicksort
- heapsort
- radix sort
- merge sort

These algorithms have been executed on datasets of considerable size, encompassing ordered data, reversed data, as well as random sequences generated from uniform, Gaussian, and Poisson distributions.

Performance assessment of these algorithms has been conducted through the examination of comparison operations, data movements, and computation times. Within the implemented algorithms, a statistical module has been incorporated to track and report the number of comparison operations, data movements, and computation times. The results are generated and subjected to correctness testing. The project also boasts a user-friendly interface, appropriate application requirements analysis, and a well-conceived application design, which will be credited accordingly.

## 🚀 How to Use

Our code repository supports direct downloading and usage, but we recommend using the `git clone` command to clone the entire code repository to your local machine for better code management and updates. Here are the specific instructions:

1.Open your terminal or command prompt.

2.Navigate to the directory where you want to clone the code repository.

3.Run the following command:

```bash
git clone git@github.com:Karenina-na/Deep-Learning-Framework.git
```

4.Wait for the cloning process to complete. Once finished, you will have a local copy of the code repository on your machine.

5.After cloning the code repository, you can use the `cd` command to navigate to the specific folder of the model and run the code.

6.Build the project

windows - MinGW - ninja

```terminal
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -G Ninja -B ./cmake-build-release ..
cmake --build ./cmake-build-release --target Sorting_Algorithm_Interface_Framework -- -j 14
```

7.Run by double-clicking the executable file in the build directory.

```terminal
./cmake-build-release/Sorting_Algorithm_Interface_Framework.exe
```

8.If you want to build for release, you can use the following command:

open Qt (Mingw) terminal

```terminal
cd ./cmake-build-release
mkdir release
windeployqt Sorting_Algorithm_Interface_Framework.exe -dir ./release -exe
```

then copy the executable file to the release directory

the release directory is ready to use

## 💻 Technology Stack

In our project, we have utilized a variety of deep learning frameworks and related libraries. Here is our primary technology stack:

- g++   12.2.0
- ninja 1.7.2
- make  4.3
- Qt    5.15.2
- cmake 3.25.3
- MinGW 11.2.0 (64-bit)

## 🤝 Contribution Guide

We greatly appreciate your willingness to contribute to our project! If you have any valuable models or paper codes to share, or if you have identified any errors or areas for improvement within the codebase, you can submit your contributions through the following methods:

1. Contribute to this endeavor, `Fork` the present undertaking.
2. Establish your distinctive branch of characteristics. (`git checkout -b feature/AmazingFeature`)
3. Submit your modifications forthwith. (`git commit -m 'Add some AmazingFeature'`)
4. Propagate your branch to the remote repository with due diligence. (`git push origin feature/AmazingFeature`)
5. Submit a formal pull request for consideration.

We shall diligently review your contribution and incorporate it into our project in a timely manner. Additionally, we extend our heartfelt gratitude for your support and interest in this endeavor!

## 📝 License

This undertaking adheres to the MIT License, and for further details, kindly refer to the [MIT](https://choosealicense.com/licenses/mit/) document.

## 📧 Notice

**Intellectual Property and Copyright**

Throughout the entire course of project development, I have placed utmost emphasis on adhering to intellectual property and copyright laws. To ensure the legality and reliability of the project, I consistently demonstrate profound respect for the intellectual property of others and have employed the use and citation of code in accordance with pertinent licensing agreements.

In my pursuit of comprehending and resolving issues within the project, I have conducted extensive internet research and perused diverse sources of relevant information. In this endeavor, I have diligently sought out code samples, solutions, and open-source tools, employing them judiciously within the parameters set forth by the applicable licensing agreements.

**Reporting Intellectual Property Concerns**

Should I have employed your code or any other intellectual property within the project, and you believe that I have encroached upon your rights, I implore you to promptly contact me. I shall honor your wishes, removing the respective code or work, and extend to you my sincerest apologies. I shall undertake appropriate measures to rectify the error and ensure that similar issues are not replicated in the future.

Please understand that in the course of project development, I have exerted every effort to guarantee the legality and compliance of the code and materials. However, owing to the open nature of the internet and the complexity of information, oversights or errors may occasionally arise. If you discover any instances where I have failed to adhere to relevant licensing agreements or infringed upon your rights, kindly provide me with substantiating evidence and detailed information, and I shall expeditiously address the matter.

## 📞 Contact Information

Should you have any questions or concerns regarding the project, please feel free to contact me via the following methods:

- Email: weizixiang0@outlook.com