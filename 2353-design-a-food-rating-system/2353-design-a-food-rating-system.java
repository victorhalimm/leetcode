public class FoodRatings {

    static class Food {
        String name;
        String cuisine;
        int rating;

        public Food(String name, String cuisine, int rating) {
            this.name = name;
            this.cuisine = cuisine;
            this.rating = rating;
        }
    }

    private Map<String, Food> foodMap = new HashMap<>();
    private Map<String, TreeMap<Integer, TreeSet<String>>> cuisineMap = new HashMap<>();

    public FoodRatings(String[] foods, String[] cuisines, int[] ratings) {
        for (int i = 0; i < foods.length; i++) {
            Food food = new Food(foods[i], cuisines[i], ratings[i]);
            foodMap.put(foods[i], food);

            cuisineMap.computeIfAbsent(cuisines[i], k -> new TreeMap<>());
            cuisineMap.get(cuisines[i])
                .computeIfAbsent(ratings[i], k -> new TreeSet<>())
                .add(foods[i]);
        }
    }

    public void changeRating(String foodName, int newRating) {
        Food food = foodMap.get(foodName);
        String cuisine = food.cuisine;
        int oldRating = food.rating;

        TreeMap<Integer, TreeSet<String>> map = cuisineMap.get(cuisine);
        TreeSet<String> oldSet = map.get(oldRating);
        oldSet.remove(foodName);
        if (oldSet.isEmpty()) {
            map.remove(oldRating);
        }

        food.rating = newRating;

        if (!map.containsKey(newRating)) {
            map.put(newRating, new TreeSet<>());
        }
        map.get(newRating).add(foodName);
    }

    public String highestRated(String cuisine) {
        TreeMap<Integer, TreeSet<String>> map = cuisineMap.get(cuisine);
        Map.Entry<Integer, TreeSet<String>> entry = map.lastEntry();
        return entry.getValue().first();
    }
}