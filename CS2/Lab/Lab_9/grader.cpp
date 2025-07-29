#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int ProcessFile(std::ifstream &inFile,int &count,int &pointsEarned);
double CalculateFinalGrade(int tot_points, int max_points);
char CalculateLetter(int final_grade);

int main(){
    std::ifstream inFile{};
    int count {0};
    double finalGrade{};
    int pointsEarned{};
    int maxPoints{};
    char letterGrade{};



    maxPoints = ProcessFile(inFile, count, pointsEarned);

    inFile.close();

    finalGrade = CalculateFinalGrade(pointsEarned, maxPoints);
    letterGrade = CalculateLetter(finalGrade);

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Number of Grades:" << std::setw(13) << count << '\n';
    std::cout << "Total Points Earned:" << std::setw(10) << pointsEarned << '\n';
    std::cout << "Max Possible Points:" << std::setw(10) << maxPoints << '\n' << '\n';
    std::cout << "Final Grade:" << std::setw(7) << letterGrade << std::setw(10) << finalGrade << '%' << '\n';
}


int ProcessFile(std::ifstream &inFile,int &count,int &pointsEarned){
    std::string fileName{};
    std::cout << "Enter the input file: ";
    std::cin >> fileName;
    std::cout << '\n';
    inFile.open(fileName);
    int grade{};
    if(!inFile){
        std::cout << fileName << " does not exist.";
        return 0;
    }
    while(inFile >> grade){
        pointsEarned += grade;
        count++;
    }

    int maxPoints{100};
    maxPoints = (maxPoints * count);
    return maxPoints;

}

double CalculateFinalGrade(int tot_points, int max_points){
    double finalGrade = (static_cast<double>(tot_points) / max_points) * 100;
    return finalGrade;
}

char CalculateLetter(int finalGrade){
    char letterGrade{};
    if(finalGrade >= 90){
        letterGrade = 'A';
    } else if(finalGrade >= 80){
        letterGrade = 'B';
    } else if(finalGrade >= 70){
        letterGrade = 'C';
    }else if(finalGrade >= 60){
        letterGrade = 'D';
    } else{
        letterGrade = 'F';
    }
    return letterGrade;
}