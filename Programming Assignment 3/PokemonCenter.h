#ifndef POKEMONCENTER_H
#define POKEMONCENTER_H
#include <iostream>
#include "Building.h"
class PokemonCenter: public Building{
private:
    unsigned int stamina_capacity;
    unsigned int num_stamina_points_remaining;
    double dollar_cost_per_stamina_point;
    //stamina_capacity is max value center can hold
    //num points remaining holds what variable name describes
    //dollar cost is the ratio of price to stamina points
public:
    enum PokemonCenterStates {
        STAMINA_POINTS_AVAILABLE = 0,
        NO_STAMINA_POINTS_AVAILABLE = 1
    };
    //checks if stamina points are available or not
    PokemonCenter();
    PokemonCenter(int in_Id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc);
    ~PokemonCenter();
    bool HasStaminaPoints();
    unsigned int GetNumStaminaPointsRemaing();
    bool CanAffordStaminaPoints(unsigned int stamina_points, double budget);
    double GetDollarCost(unsigned int stamina_points);
    unsigned int DistributeStamina(unsigned int points_needed = 0);
    bool Update();
    void ShowStatus();
    bool ShouldBeVisible();
};
#endif

