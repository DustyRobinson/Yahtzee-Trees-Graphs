#include <iostream>
#include <algorithm>
#include "Dice.h"

void Dice::getVal()
{
    for (int i = 0; i < size; i++) {
        insertNode(0,i+1);
    }
}

//Function that displays the dice binary tree
void Dice::roll()
{
    PreOrder();
}

//Function for re-rolling dice
void Dice::reRoll()
{
    //char variable
    char choice;
    char pos;
    int size = 5;

    //prompting user(s) for which dice to keep and which to re-roll
    cout << "Choose which dice you want to keep. R - reRoll and K - Keep dice." << endl;

    for (int j = 0; j < 2; j++) {
        //displaying dice
        cout << "Roll " << j + 1 << ": ";
        roll();
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            do {
                cout << "Die " << i + 1 << ": ";
                cin >> choice;
            } while (toupper(choice) != 'R' && toupper(choice) != 'K');

            //assigns new value to each node in the binary tree by which the user choose to re-roll
            if (toupper(choice) == 'R') {
                search(i+1);
            }
        }
    }
    //calls function to display the binary tree
    cout << endl << "Roll 3 : ";
    roll();
    cout << endl;

    //storing values from the binary tree to an array
    for(int i = 0; i < 5;i++){
        array[i] = transfer(i+1);
    }
    //calls recursive quick sort to sort temp array from
    quickSort(0,size-1);
}
//Function to get the total values stored in 1D array
int Dice::product()
{
    //temp variable
    int sum = 0;

    //iterates through array and adds values store in memory address to sum
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;   //returned the sum of the array
}
//Function for getting the sum of values of a give value
int Dice::result(int p)
{
    //variable to store sum of values chosen set to 0
    int sum = 0;

    //searches for matching values in the array from one passed by player
    for (auto i =0; i < size; i++)
    {
        if (array[i] == p)
        {
            sum += array[i]; // if match is found add value to sum
        }
    }
    return sum;  //return sum
}
//function to check the max frequency of a value
int Dice::maxFreq()
{
    // checking max frequency of a number to see if its 3, 4 or 5
    int max = 0;
    int count = 0;
    for (int i = 0; i < size-1; i++)
    {
         // set count to zero after each iteration
        for (int j = 0; j < size; j++)
        {
            if (array[i] == array[j])
            {
                count++; // increasing frequency counters
            }
            if (count > max) // assign count to max if counter is greater than max
            {
                max = count; // making max frequency a new max frequency
            }
        }
    }
    return max;   //return the max frequency passed by player
}
//function to verify player has a full house
int Dice::full()
{
    //sum variable
    int sum = 0;
    //checks values for matching pair and three of a kind
    if (((array[0] == array[1]) && (array[1] == array[2])) &&
        (array[3] == array[4]) && (array[2] != array[3]) ||
        ((array[0] == array[1]) && ((array[2] == array[3]) &&
            (array[3] == array[4])) && (array[1] != array[2])))
    {
        sum = 25; //assigns 25 points if both matches are found
    }
    else
    {
        sum = 0; // assigns 0 if not both matches are not found
    }
    return sum; //return sum
}
//function to check for a small straight
int Dice::smallStraight()
{
 // sum variable
    int sum = 0;
    for (int i = 0; i < size - 1; i++)
    {
        //checking for repeated numbers
        for (int j = 0; j < size; j++) {
            if (array[i] == array[j])
            {
                array[i] = 7; // need to assign value outside values to check
                partition(0,size);
                quickSort(0,size); //sort function is called to move extra value to end
            }
        }
    }
    //checks from small straight in sorted array
    if (((array[0] == 1) && (array[1] == 2) && (array[2] == 3) && (array[3] == 4)) ||
        ((array[0] == 2) && (array[1] == 3) && (array[2] == 4) && (array[3] == 5)) ||
        ((array[0] == 3) && (array[1] == 4) && (array[2] == 5) && (array[3] == 6)) ||
        ((array[1] == 1) && (array[2] == 2) && (array[3] == 3) && (array[4] == 4)) ||
        ((array[1] == 2) && (array[2] == 3) && (array[3] == 4) && (array[4] == 5)) ||
        ((array[1] == 3) && (array[2] == 4) && (array[3] == 5) && (array[4] == 6)))
    {
        sum = 30; //assigns 30 points to sum if small straight is found
    }
    else
    {
        sum = 0; //assigns 0 points to sum if small straight is not found
    }
    return sum;   //returns sum
}
//checking for large straight functions
int Dice::largeStraight()
{
   int sum = 0;
    //searches for matching
    if (((array[0] == 1) && (array[1] == 2) && (array[2] == 3)
         && (array[3] == 4) && (array[4] == 5)) ||
        ((array[0] == 2) && (array[1] == 3) && (array[2] == 4)
            && (array[3] == 5) && (array[4] == 6)))
    {
        sum = 40; // assigns 40 points if player has large straight
    }
    else
    {
        sum = 0; //assigns 0 points if player does not have large straight
    }
    return sum; // returns points
}
int Dice::partition(int start, int end)
{
 
    int pivot = array[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (array[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(array[pivotIndex], array[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (array[i] <= pivot) {
            i++;
        }
 
        while (array[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(array[i++], array[j--]);
        }
    }
 
    return pivotIndex;
}
 void Dice::quickSort(int start, int end)
{
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(start, end);
 
    // Sorting the left part
    quickSort(start, p - 1);
 
    // Sorting the right part
    quickSort(p + 1, end);
}
 //function to insert nodes
void Dice::insert(Tree*& ptr, Tree *&node) {
    //checking for an empty tree
    if (ptr == nullptr) {
        ptr = node;
    }
    //adding dice nodes to left and right of the tree
    else if (node->die < ptr->die){
        insert(ptr->left, node);
    }
    else {
        insert(ptr->right, node);
    }
}
//function to store data for the binary tree in each node
void Dice::insertNode(int n, int d) {
    //setting node pointer to null 
    Tree* node = nullptr;
    //adding the numeric value of each dies and storing values 
    node = new Tree;
    node->die = d;
    node->data = n;
    node->left = nullptr;
    node->right = nullptr;
    //calling insert function to add each node of the tree
    insert(root, node);
}
//function to transfer the values chosen by the user into another storage container
int Dice::transfer(int n){
    //setting ptr to traverse the tree
    Tree* ptr = root;
    //Traversing through each parent and child of the tree and returning the value stored
    while (ptr) {
        if (ptr->die == n) {
           return ptr->data;
        }
        else if (n < ptr->die) {
            ptr = ptr->left;
        }
        else {
            ptr = ptr->right;
        }
    }
}
//printing the values the user obtained during each roll in order they were generated
void Dice::PreOrder(Tree* ptr)const {
    if (ptr) {
        cout << ptr->data << " ";
        PreOrder(ptr->left);
        PreOrder(ptr->right);
    }
}
//function to destroy each node in the tree to free up memory
void Dice::destroy(Tree* ptr) {
    if (ptr) {
        if (ptr->left) {
            destroy(ptr->left);
        }
        if (ptr->right) {
            destroy(ptr->right);
            delete ptr;
        }
    }
}
//searching for each node in the tree 
void Dice::search(int n) {
    //setting node to root of tree
    Tree* ptr = root;
    //while loop to search for a specific node and returning the data from node found
    while (ptr) {
        if (ptr->die == n) {
            ptr->data = rand() % 6 + 1;
            return;
        }
        else if (n < ptr->die) {
            ptr = ptr->left;
        }
        else {
            ptr = ptr->right;
        }
    }
}
