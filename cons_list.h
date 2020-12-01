#include<stdio.h>
#include<typeinfo>

/*For now, I will only focus on adding primitive data types to the list*/

/*typedef enum {
	int = 0,
	signed short int,
	signed long int,
	signed long long int,
	unsigned char,
	unsigned short int,
	unsigned int,
	unsigned long int,
	unsigned long long int,
	float,
	double,
	long double,
	bool
}typeID;*/

struct list_of_types {
	int INT_T= 0;
	signed short int SSINT_T = 0;
	signed long int SLINT_T = 0;
	signed long long int SLLINT_T = 0;
	unsigned char UCHAR_T = 0;
	unsigned short int USINT_T = 0;
	unsigned int UINT_T = 0;
	unsigned long int ULINT_T = 0;
	unsigned long long int ULLINT_T = 0;
	float FLOAT_T = 0;
	double DOUBLE_T = 0;
	long double LDOUBLE_T = 0;
	bool BOOL_T = 0;
};

typedef enum {
	int_type = 0,
	ssint_type,
	slint_type,
	sllint_type,
	uchar_type,
	usint_type,
	uint_type,
	ulint_type,
	ullint_type,
	float_type,
	double_type,
	ldouble_type,
	bool_type,
	err
}typeID;

template <typename T>
struct list_item {
	typeID type;
	T data = 0;
	void* next = nullptr;
};
template<typename T>
struct list_item <T*>{
	T* data = nullptr;
	list_item* next = nullptr;
	size_t size = 0;
};

class Cons_List {
	private:
		void* list_car; // aka the head
		void* list_cdr; // ptr to the second part of the list
		list_of_types type_list;

		template<typename T>
		typeID getTypeId(T item){
			typeID ret_type;
			if(typeid(type_list.INT_T) == typeid(item))
				ret_type = int_type;
			else if(typeid(type_list.SSINT_T) == typeid(item))
				ret_type = ssint_type;
			else if(typeid(type_list.SLINT_T) == typeid(item))
				ret_type = slint_type;
			else if(typeid(type_list.SLLINT_T) == typeid(item))
				ret_type = sllint_type;
			else if(typeid(type_list.UCHAR_T) == typeid(item))
				ret_type = uchar_type;
			else if(typeid(type_list.USINT_T) == typeid(item))
				ret_type = usint_type;
			else if(typeid(type_list.UINT_T) == typeid(item))
				ret_type = uint_type;
			else if(typeid(type_list.ULINT_T) == typeid(item))
				ret_type = ullint_type;
			else if(typeid(type_list.ULLINT_T) == typeid(item))
				ret_type = ullint_type;
			else if(typeid(type_list.FLOAT_T) == typeid(item))
				ret_type = float_type;
			else if(typeid(type_list.DOUBLE_T) == typeid(item))
				ret_type = double_type;
			else if(typeid(type_list.LDOUBLE_T) == typeid(item))
				ret_type = ldouble_type;
			else if(typeid(type_list.BOOL_T) == typeid(item))
				ret_type = bool_type;
			else
				ret_type = err;

			return ret_type;
		}
	public:
		// constructor and destructor
		/*Cons_List(T item1, U item2){
			// initialize a cons_list
			list_item<int> empty;
			empty.data = 0;
			empty.next = NULL;
			empty.type = int_type;

			list_item<U> new_cdr;
			new_cdr.data = item2;
			new_cdr.next = &empty;
			new_cdr.type = getTypeId(item2);

			list_item<T> new_car;
			new_car.data = item1;
			new_car.next = &new_cdr;
			new_car.type = getTypeId(item1);

			this->list_car = &new_car;
			this->list_cdr = &new_cdr;
		};
		Cons_List<T>(T item1, T item2) {
			list_item<int> empty;
			empty.data = 0;
			empty.next = NULL;
			empty.type = int_type;

			list_item<T> new_cdr;
			new_cdr.data = item2;
			new_cdr.next = &empty;
			new_cdr.type = getTypeId(item2);

			list_item<T> new_car;
			new_car.data = item1;
			new_car.next = &new_cdr;
			new_car.type = getTypeId(item1);

			this->list_car = &new_car;
			this->list_cdr = &new_cdr;
		};*/
		Cons_List() {
			list_item<int> empty;
			empty.data = 0;
			empty.next = NULL;
			empty.type = int_type;

			this->list_cdr = &empty;
			this->list_cdr = &empty;
		};
		~Cons_List();

		template<typename unkn1>
		void cons(unkn1 new_item, Cons_List list){
			printf("test1");
		};

		template<typename unkn2, typename unkn3>
		Cons_List cons(unkn2 item1, unkn3 item2){
			printf("test2");
		};

		template<typename Append_Item>
		void append(Append_Item item1, Cons_List list) {
			// append an item to the list
		};

		template<typename Car_Item>
		Car_Item car(Cons_List list) {
			// return the first element of the list
		};

		Cons_List cdr(Cons_List list) {
			// return cdr, the pointer to the second item in the list
			// (aka the rest of the list)
		};
};