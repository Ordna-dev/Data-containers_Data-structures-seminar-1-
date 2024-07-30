# StoreProductManager
StoreProductManager is a C++ program designed to manage the products of a store.

## Product Model

Products are modeled using a struct containing the following data:

- Name
- Stock
- Unit of measurement
- Type of unit of measurement
- Price
- Unit Types

### The types of unit measurements are:
- Liters
- Kilograms
- Grams
- Pieces

The units of measurement are modeled using a union, and the types of units are modeled using an enumeration.

## Compilation
Use the g++ compiler to compile StoreProductManager.

```bash
g++ -o store_product_manager store_product_manager.cpp
```

## Usage

Once compiled, run the executable to interact with the cyclic menu:

```bash
./store_product_manager
```

## Features
The menu options are programmed using enumerators and include:

1. Add
2. View
3. Search
4. Exit
Each menu option has a corresponding procedure.

## Instructions
1. Run the program.
2. Follow the on-screen menu to:
- Add a new product.
- View all products.
- Search for a specific product.
- Exit the program.

## Array Storage
The program can store products in an array of size MAX_PRODUCTS, with MAX_PRODUCTS being a positive constant of your choice.
