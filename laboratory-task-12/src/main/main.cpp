#include "../class/list.hpp"
#include "../class/fraction.hpp"
#include "../class/matrix.hpp"

int main()
{
    try{
/*================Демонстрация дроби================*/

    std::cout << "/*================Fraction demonstration================*/" << std::endl << std::endl;

    Fraction fraction1(44, 55);
    Fraction fraction2(fraction1);

    std::cout << "  Numerator of fraction1: " << fraction1.getNumerator() << std::endl;
    std::cout << "  Denumerator of fraction1: " << fraction1.getDenumerator() << std::endl;
     
    std::cout << "  Numerator of fraction2: " << fraction2.getNumerator() << std::endl;
    std::cout << "  Denumerator of fraction2: " << fraction2.getDenumerator() << std::endl;
    
    fraction1.setNumerator(77);
    fraction1.setDenumerator(-6);
    std::cout << "  fraction1: " << fraction1 << std::endl;

    fraction1 += fraction2;
    std::cout << "  fraction1 + fraction2 = " << fraction1 << std::endl;

    fraction1 -= fraction2;
    std::cout << "  fraction1 - fraction2 = " << fraction1 << std::endl;

    fraction1 *= fraction2;
    std::cout << "  fraction1 * fraction2 = " << fraction1 << std::endl;

    fraction1 /= fraction2;
    std::cout << "  fraction1 / fraction2 = " << fraction1 << std::endl;

    Fraction tempFraction;
    tempFraction = fraction1;
    std::cout << "  tempFraction = " << tempFraction << std::endl;

    tempFraction = 5;
    std::cout << "  tempFraction = " << tempFraction << std::endl;

    tempFraction = fraction1;
    std::cout << "  tempFraction == fraction1 = "<< (tempFraction == fraction1 ? "true" : "false") << std::endl; 

    std::cout << "  tempFraction < fraction2 = " << (tempFraction < fraction2 ? "true" : "false") << std::endl; 
    std::cout << "  fraction2 > fraction1 = " << (fraction2 > fraction1 ? "true" : "false") << std::endl; 

    std::cout << "  -tempFraction = " << -tempFraction << std::endl;

    std::cout << "  ++tempFraction = " << ++tempFraction << std::endl;
    std::cout << "  tempFraction++ = " << tempFraction++ << std::endl;
    std::cout << "  tempFraction = " << tempFraction << std::endl;

    std::cout << "  --tempFraction = " << --tempFraction << std::endl;
    std::cout << "  tempFraction-- = " << tempFraction-- << std::endl;
    std::cout << "  tempFraction = " << tempFraction << std::endl;

    std::cout << "  !tempFraction = " << !tempFraction << std::endl;

    std::cout << "  Enter fraction: ";
    std::cin >> tempFraction;
    std::cout << std::endl;
    std::cout << "  tempFraction = " << tempFraction << std::endl;


    std::cout << "  tempFraction in double = " << static_cast<double>(tempFraction) << std::endl; 


/*================Демонстрация матрицы================*/


    std::cout << std::endl <<  "/*================Matrix demonstration================*/" << std::endl << std::endl;


    Matrix mtrx1(8, 9);
    Matrix mtrx2(mtrx1);
    std::cout << "  mtrx1 rows = " << mtrx1.getRows() << std::endl;
    std::cout << "  mtrx1 columns = " << mtrx1.getColumns() << std::endl;

    std::cout << "  mtrx2 rows = " << mtrx2.getRows() << std::endl;
    std::cout << "  mtrx2 columns = " << mtrx2.getColumns() << std::endl;

    for (size_t i = 0; i < mtrx1.getRows(); ++i) {
        for (size_t j = 0; j < mtrx2.getColumns(); ++j) {
            mtrx1[i][j] = (i + j + 1);   
        }
    }
    
    std::cout << "  mtrx1: " << std::endl << mtrx1 << std::endl;
    mtrx2 = mtrx1;
    std::cout << "  mtrx2: " << std::endl << mtrx2 << std::endl;

    mtrx2 = 8;
    std::cout << "  mtrx2: " << std::endl << mtrx2 << std::endl;

    std::cout << "  mtrx2 * 2: " << std::endl << mtrx2 * 2 << std::endl; 
    std::cout << "  mtrx2 / 2: " << std::endl << mtrx2 / 2 << std::endl; 

    mtrx2 = mtrx1 * 2;

    std::cout << "  mtrx1 + mtrx2" << std::endl << mtrx1 + mtrx2 << std::endl;

    std::cout << "  mtrx2 - mtrx1" << std::endl << mtrx2 - mtrx1 << std::endl;

    Matrix mtrx3(3, 3);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            mtrx3[i][j] = i + j + 1;
        }
    }
    
    Matrix mtrx4(mtrx3);



    std::cout << "  mtrx3 * mtrx4" << std::endl << mtrx3 * mtrx4 << std::endl; 
    std::cout << "  mtrx3 == mtrx4 = "<< (mtrx3 == mtrx4 ? "true" : "false") << std::endl; 

    std::cout << "  Enter mtrx3: ";
    std::cin >> mtrx3;
    std::cout << "  mtrx3: " << std::endl << mtrx3 << std::endl; 


/*================Демонстрация списка================*/

    std::cout << "/*================List demonstration================*/" << std::endl << std::endl;

    List<int> list1;
    List<int> list2(list1);

    list1.printList();
    list2.printList(); 

    list1.pushBack(78);
    list1.pushBack(45);
    list2.pushFront(89);
    list2.pushFront(49);

    std::cout << "  list1: ";
    list1.printList();
    std::cout << "  list2: ";
    list2.printList();

    list1.deleteItem(0);
    size_t temp = 0;
    list2.deleteItem(89, temp);

    std::cout << "  list1: ";
    list1.printList();
    std::cout << "  list2: ";
    list2.printList();

    list1.clear();
    std::cout << "  list1: ";
    list1.printList();

    for (size_t i = 0; i < 5; ++i) {
        list1.pushBack(i + 1);
    }
    
    std::cout << "Elemnt 2, in this list have position: " << list1.find(2, temp) << std::endl; 

    list1.insert(3, 89);
    std::cout << " list1: ";
    list1.printList();

    for (size_t i = 0; i < 5; ++i) {
        list2.pushBack(i + 6);
    }

    list1.merge(list2, 6);
    std::cout << " list1: ";
    list1.printList();

    list1.revers();
    std::cout << " list1: ";
    list1.printList();

    list2 = (list1 + list2);
    std::cout << " list2: ";
    list2.printList();

    list2.editList();

    list2.checkList([](int item){std::cout << item << " ";});

    std::cout<< std::endl;

    list2.clear();
    std::cout << (list2.empty() ? " empty" : "  filled") << std::endl;
    } 
    catch(std::invalid_argument &err) {
        std::cerr << "Invalid argument: " << err.what() << std::endl;
    }
    catch(std::logic_error &err) {
        std::cerr << "Logic error: " << err.what() << std::endl;
    }
    catch(std::out_of_range &err) {
        std::cerr << "Out of range: " << err.what() << std::endl;
    }
    catch(std::exception &err) {
        std::cerr << err.what() << std::endl;
    }
    return 0;
}
