print("Expert System for Restaurant Menu recommendation based on customer preferences")

def recommendation(preferences):
    menu = {
        "veg": ["paneer butter", "veg biryani", "dal","rice"],
        "chinese": ["chow mein", "spring rolls", "manchurian"],
        "south indian": ["dosa", "idli", "uttapam"]
    }

    if preferences in menu:
        print("\nRecommended Dishes for", preferences, ":")
        for dish in menu[preferences]:
            print(dish)
    else:
        print("Sorry, we don't have recommendations for that preference.")

pref = input("Enter your food preference (veg / chinese / south indian): ").lower()
recommendation(pref)