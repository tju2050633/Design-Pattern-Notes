package Builder;

import Builder.Meal.Meal;
import Builder.Meal.MealBuilder;

public class BuilderTest {
    public static void main(String[] args) {
        MealBuilder mealBuilder = new MealBuilder();

        // vegmeal
        Meal vegMeal = mealBuilder.prepareVegMeal();
        
        System.out.println("Veg Meal");
        vegMeal.showItems();
        System.out.println("Total Cost: " + vegMeal.getCost());

        // nonvegmeal
        
        Meal nonVegMeal = mealBuilder.prepareNonVegMeal();
        
        System.out.println("\n\nNon-Veg Meal");
        nonVegMeal.showItems();
        System.out.println("Total Cost: " + nonVegMeal.getCost());
    }
}
