#include <stdio.h>

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  enum CarType type;
  double km;
  double gas;
};

void print_car(struct Car vehicle)
{
    if (vehicle.type != TESLA) {

        printf("Number: %d\nGas: %.2f\nKm: %.2f", vehicle.type + 1, vehicle.gas, vehicle.km);
    }
    else {

    printf("Number: %d\nKm: %.2f\n", vehicle.type + 1, vehicle.km);
    }
}

// TODO:
// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

int main() {

    struct Car Car_1 = {VOLVO, 350, 8};
    struct Car Car_2 = {TOYOTA, 400, 6};
    struct Car Car_3 = {LAND_ROVER, 300, 10};
    struct Car Car_4 = {TESLA, 200, 0};

    print_car(Car_2);

  return 0;
}

