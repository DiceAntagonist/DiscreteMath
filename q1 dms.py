from itertools import chain, combinations


class Set:
    def __init__(self):
        self.set1 = {1, 9, 8, 7, 9}
        self.set2 = {0, 3, 4, 2, 7}

    def display_sets(self):
        print("set1:", self.set1)
        print("set2:", self.set2)

    def membership(self, element):
        return element in self.set1 or element in self.set2

    def powerset(self, set_input):
        elements = list(set_input)
        power_set = list(chain.from_iterable(combinations(elements, r) for r in range(len(elements) + 1)))
        return power_set

    def subset(self):
        return self.set1.issubset(self.set2) or self.set2.issubset(self.set1)

    def union(self):
        return self.set1.union(self.set2)

    def intersection(self):
        return self.set1.intersection(self.set2)

    def complement(self, universal_set):
        return universal_set.difference(self.set1)

    def set_difference(self):
        return self.set1.difference(self.set2)

    def symmetric_difference(self):
        return self.set1.symmetric_difference(self.set2)

    def cartesian_product(self):
        return [(x, y) for x in self.set1 for y in self.set2]


def display_menu():
    print("------ Set Display Menu ------")
    print("1. Display Sets")
    print("2. Check Membership")
    print("3. Power Set")
    print("4. Check Subset")
    print("5. Union")
    print("6. Intersection")
    print("7. Complement")
    print("8. Set Difference")
    print("9. Symmetric Difference")
    print("10. Cartesian Product")
    print("0. Exit")


set_display = Set()

while True:
    display_menu()

    choice = input("Enter your choice (0-10): ")
    print()

    if choice == "1":
        set_display.display_sets()
    elif choice == "2":
        element = input("Enter an element to check membership: ")
        print("Membership:", set_display.membership(element))
    elif choice == "3":
        set_choice = input("Enter the set choice (1 or 2): ")
        if set_choice == "1":
            power_set = set_display.powerset(set_display.set1)
        elif set_choice == "2":
            power_set = set_display.powerset(set_display.set2)
        else:
            print("Invalid set choice.")
            continue
        print("Power Set:")
        for subset in power_set:
            print(subset)
    elif choice == "4":
        print("Is one set a subset of the other?", set_display.subset())
    elif choice == "5":
        print("Union:", set_display.union())
    elif choice == "6":
        print("Intersection:", set_display.intersection())
    elif choice == "7":
        universal_set = set(range(1, 10))
        print("Complement of set1:", set_display.complement(universal_set))
    elif choice == "8":
        print("Set Difference:", set_display.set_difference())
    elif choice == "9":
        print("Symmetric Difference:", set_display.symmetric_difference())
    elif choice == "10":
        print("Cartesian Product:", set_display.cartesian_product())
    elif choice == "0":
        print("Exiting the program...")
        break
    else:
        print("Invalid choice. Please try again.")

    print()
