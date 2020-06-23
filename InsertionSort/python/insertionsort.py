from typing import List

def insertion_sort(my_list: List):
    for front in range(1,len(my_list)):
        current_item = my_list[front]
        back = front - 1
        while(my_list[back] < current_item and back >= 0):
            my_list[back+1] = my_list[back]
            back -=1
        print(my_list)
        my_list[back+1] = current_item
    
    return my_list


if __name__ == '__main__':
    my_list = "n j z d e f g h i c k l m a o p q r s t u v w x y b".split()
    sorted_list = insertion_sort(my_list)
    print(sorted_list)
