#include <iostream>
//#include "Iterable.h"
//#include "InheritedIterable.h"
#include "GTUIterator.h"
#include "GTUIteratorConst.h"
#include "Global.h"
#include "GTUSet.h"
#include "GTUVector.h"
#include "GTUArray.h"

using namespace MYNAMESPACE;
using namespace std;


int main()
{
    cout << "-----GTUVector Class Test-----\n\n\n" << endl;
    GTUVector<int> vector1;
    cout << "Vector1's size: " << vector1.size() << endl;
    cout << "GTUVector Class empty function:" << endl;
    if(vector1.empty() == true)
        cout << "Vector1 is empty!" << endl;
    else
        cout << "Vector1 is not empty!" << endl;     
    cout << "GTUVector Class add function: " << endl;
    vector1.add(52);
    vector1.add(90);
    vector1.add(45);
    vector1.add(16);
    vector1.add(24);
    cout << "\nVector1's elements: " << endl;
    for(auto iter = vector1.begin(); iter != vector1.end(); ++iter)
        cout << *iter << " " << endl;
    cout << "\nAfter add operation, GTUVector Class empty function:" << endl;
    if(vector1.empty() == true)
        cout << "Vector1 is empty!" << endl;
    else
        cout << "Vector1 is not empty!" << endl;
    cout << "\nGTUVector Class erase function:" << endl;
    cout << "Before erase operation, Vector1's size :" << vector1.size() << endl;
    cout << "Erase first element:" << endl;
    GTUIterator<int> iter1 = vector1.begin();
    vector1.erase(iter1);
    cout << "After erase operation, Vector1's elements:" << endl;
    for(auto iter = vector1.begin(); iter != vector1.end(); ++iter)
        cout << *iter << " " << endl;
    cout << "\nGTUVector Class clear function:" << endl;
    cout << "Before clear operation, Vector1's size:" << vector1.size() << endl;
    vector1.clear();
    cout << "After clear operation, Vector1's size: " << vector1.size() << endl;
    GTUVector<int> vector2;
    cout << "\nVector2 is being creating:" << endl;
    for(int i = 0; i < 10; ++i)
    {
        cout << "Add " << i << endl;
        vector2.add(i);
    }
    cout << "\nGTUVector Class copy constructor (Vector2 to Vector3): " << endl;
    GTUVector<int> vector3(vector2);
    cout << "After copy constructor operation, Vector3's size: " << vector3.size() << endl;
    cout << "Vector3's elements:" << endl;
    for(auto iter = vector3.begin(); iter != vector3.end(); ++iter)
        cout << *iter << " " << endl;
    GTUVector<int> vector4;
    cout << "\nGTUVector Class assignmet operator:(Assign Vector3 to Vector4)" << endl;
    cout << "Before assignment operator, Vector4's size: " << vector4.size() << endl;
    vector4 = vector3;
    cout << "After assignment operator, Vector4's size:" << vector4.size() << endl;
    cout << "Vector4's elements:" << endl;
    for(auto iter = vector4.begin(); iter != vector4.end(); ++iter)
        cout << *iter << " " << endl;
    
    GTUVector<int> vector5(7);
    cout << "\nGTUVector Class operator[] (Assigning and Printing):" << endl;
    cout << "Assign 5 to index 0:" << endl;
    vector5[0] = 5;
    cout << "Vector5[0] : " << vector5[0] << endl;    

    cout << "\n\n-----GTUSet Class Test-----\n\n\n" << endl;    
    GTUSet<double> set1;
    cout << "Set1'size: " << set1.size() << endl;
    cout << "\nGTUSet Class empty function: " << endl;
    if(set1.empty() == true)
        cout << "Set1 is empty!" << endl;
    else
        cout << "Set1 is not empty!" << endl;
    cout << "GTUSet Class add function:" << endl;
    set1.add(1.43);
    set1.add(9.68);
    set1.add(13.07);
    set1.add(22.68);
    set1.add(95.51);
    cout << "Set1's elements:" << endl;
    for(auto iter = set1.begin(); iter != set1.end(); ++iter)
        cout << *iter << " " << endl;
    
    cout << "\nGTUSet Class search function (Set1, search 22.68):" << endl;
    cout << "Index : " << set1.search(22.68) << endl;
    
    cout << "\nAfter add operation, GTUSet Class empty function:" << endl;
    if(set1.empty() == true)
        cout << "Set1 is empty!" << endl;
    else
        cout << "Set1 is not empty!" << endl;               
    cout << "\nAdding the same element to the set (95.51):" << endl;
    set1.add(95.51);
    
    cout << "\nGTUSet Class erase function:" << endl;
    cout << "\nBefore erase operation, Set1's size: " << set1.size() << endl;
    cout << "\nErase second element: " << endl;
    GTUIterator<double> iter2 = set1.begin();
    ++iter2;
    set1.erase(iter2);
    cout << "After erase operation, Set1's size: " << set1.size() << endl;
    cout << "After erase operation, Set1's elements:" << endl;
    for(auto iter = set1.begin(); iter != set1.end(); ++iter)
        cout << *iter << " " << endl;    
    cout << "\nGTUSet Class clear function:" << endl;
    cout << "\nBefore clear operation, Set1's size: " << set1.size() << endl;
    set1.clear();
    cout << "\nAfter clear operation, Set1's size: " << set1.size() << endl;

    cout << "\nSet2 is being creating:" << endl;
    GTUSet<int> set2;
    for(int i = 0; i < 10; ++i)
    {
        cout << "Add " << i << endl;
        set2.add(i);
    }

    cout << "\nGTUSet Class copy constructor: (Set2 to Set3)" << endl;
    GTUSet<int> set3(set2);
    cout << "\nAfter copy constructor operation, Set3's size:" << set3.size() << endl;
    cout << "\nSet3's elements:" << endl;
    for(auto iter = set3.begin(); iter != set3.end(); ++iter)
        cout << *iter << " " << endl;
    GTUSet<int> set4;
    cout << "\nGTUSet Class assignment operator: (Set3 to Set4)" << endl;
    cout << "\nBefore the assignment operation, Set4's size :" << set4.size() << endl;
    set4 = set3;
    cout << "\nAfter the assignment operation, Set4's size :" << set4.size() << endl;
    cout << "Set4's elements:" << endl;    
    for(auto iter = set4.begin(); iter != set4.end(); ++iter)
        cout << *iter << " " << endl;
    cout << "\n\n-----GTUArray Class Test-----\n" << endl;
    
    cout << "Array1 is being creating with initializer list..." << endl;
    GTUArray<char, 4> array1 = {'a', 'b', 'c', 'd'};   
    cout << "Array1's size: " << array1.size() << endl;
    cout << "\nArray1's elements:" << endl;
    for(auto iter = array1.begin(); iter != array1.end(); ++iter)
        cout << *iter << " " << endl;
    cout << "\nGTUArray Class empty function:" << endl;
    if(array1.empty() == true)
        cout << "Array1 is empty!" << endl;
    else
        cout << "Array1 is not empty!" << endl;
    cout << "\nArray1's first element: (front function) " << array1.front() << endl;
    cout << "\nArray1's last element: (back function) " << array1.back() << endl;

    cout << "\nArray1's operator[]: (Assigning and Printing)" << endl;
    cout << "Array1's [2] = 'h' (Assigning)" << endl;
    array1[2] = 'h';
    cout << "Array1[2] = " << array1[2] << endl; 

    cout << "\nGTUArray Class copy constructor: (Array1 to Array2)" << endl;
    GTUArray<char, 4> array2(array1);
    cout << "\nAfter copy constructor operation, Array2's size :" << array2.size() << endl;
    cout << "\nArray2's elements:" << endl;
    for(auto iter = array2.begin(); iter != array2.end(); ++iter)
        cout << *iter << " " << endl;

    cout << "\nGTUArray Class assignment operator: (Array2 to Array3)" << endl;
    GTUArray<char, 4> array3;
    array3 = array2;
    cout << "\nAfter assignment operation, Array3's size: " << array3.size() << endl;
    cout << "\nArray3's elements:" << endl;
    for(auto iter = array3.begin(); iter != array3.end(); ++iter)
        cout << *iter << " " << endl;
       
    return 0;
}