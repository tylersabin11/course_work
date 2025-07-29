#include <iostream> 
#include <string>

// template<typename T, size_t Size, typename V>
// int find(T (&arr)[Size], V& value){
//     for(size_t i{0}; i < Size; i++){
//         if(arr[i] == value){
//             return i;
//         }
//     }
//     return -1;
// };


// int main(){

//     //std::string arr[5] {"hello", "about", "computer", "science", "jam"};
//     int arr[5] {1,2,3,4,5};
//     int index{};

//     index = find(arr, 2);
//     if(index !=-1){
//         std::cout << "Index found: " << index << '\n';
//     }else{
//         std::cout << "Index not found\n";
//     }


//     return 0;
// }

#include <iostream>
#include <string>

template<typename T, size_t Size, typename V>
int find(T (&arr)[Size], const V& value) {
    for(size_t i = 0; i < Size; ++i) {
        if(arr[i] == value) {
            return i;
        }
    }
    return -1;
}

int main() {
    std::string arr[5] {"hello", "about", "computer", "science", "jam"};
    int index = find(arr, std::string("about"));

    if(index != -1) {
        std::cout << "Index found: " << index << '\n';
    } else {
        std::cout << "Index not found\n";
    }

    return 0;
}
