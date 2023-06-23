class SET:
    def __init__(self):
        self.elements = set()

    def ismember(self, element):
        return element in self.elements

    def powerset(self):
        from itertools import chain, combinations
        power_set = list(chain.from_iterable(combinations(self.elements, r) for r in range(len(self.elements) + 1)))
        return power_set

    def subset(self, other_set):
        return self.elements.issubset(other_set.elements)

    def union(self, other_set):
        result = SET()
        result.elements = self.elements.union(other_set.elements)
        return result

    def intersection(self, other_set):
        result = SET()
        result.elements = self.elements.intersection(other_set.elements)
        return result

    def complement(self, universal_set):
        result = SET()
        result.elements = universal_set.elements.difference(self.elements)
        return result

    def difference(self, other_set):
        result = SET()
        result.elements = self.elements.difference(other_set.elements)
        return result

    def symmetric_difference(self, other_set):
        result = SET()
        result.elements = self.elements.symmetric_difference(other_set.elements)
        return result

    def cartesian_product(self, other_set):
        result = SET()
        result.elements = {(a, b) for a in self.elements for b in other_set.elements}
        return result


# Menu-driven program

def display_menu():
    print("---------- SET Operations Menu ----------")
    print("1. Check if element belongs to the set")
    print("2. List all elements of the power set")
    print("3. Check if one set is a subset of another")
    print("4. Union of two sets")
    print("5. Intersection of two sets")
    print("6. Complement of a set")
    print("7. Set difference")
    print("8. Symmetric difference")
    print("9. Cartesian product of sets")
    print("0. Exit")
    print("-----------------------------------------")

def read_set():
    elements = input("Enter elements of the set (space-separated): ").split()
    s = SET()
    s.elements = set(elements)
    return s

def read_element():
    element = input("Enter the element to check: ")
    return element

def read_sets():
    set1 = read_set()
    set2 = read_set()
    return set1, set2

def main():
    universal_set = read_set()

    while True:
        display_menu()
        choice = input("Enter your choice: ")

        if choice == "1":
            element = read_element()
            s = read_set()
            print(f"Is {element} a member of the set? {s.ismember(element)}")

        elif choice == "2":
            s = read_set()
            print("Power set:")
            power_set = s.powerset()
            for subset in power_set:
                print(subset)

        elif choice == "3":
            set1, set2 = read_sets()
            if set1.subset(set2):
                print("Set 1 is a subset of Set 2.")
            else:
                print("Set 1 is not a subset of Set 2.")

        elif choice == "4":
            set1, set2 = read_sets()
            union_set = set1.union(set2)
            print("Union of Set 1 and Set 2:", union_set.elements)

        elif choice == "5":
            set1, set2 = read_sets()
            intersection_set = set1.intersection(set2)
            print("Intersection of Set 1 and Set 2:", intersection_set.elements)

        elif choice == "6":
            s = read_set()
            complement_set = s.complement(universal_set)
            print("Complement of the set:", complement_set.elements)

        elif choice == "7":
            set1, set2 = read_sets()
            difference_set = set1.difference(set2)
            print("Set difference of Set 1 and Set 2:", difference_set.elements)

        elif choice == "8":
            set1, set2 = read_sets()
            symmetric_difference_set = set1.symmetric_difference(set2)
            print("Symmetric difference of Set 1 and Set 2:", symmetric_difference_set.elements)

        elif choice == "9":
            set1, set2 = read_sets()
            cartesian_product_set = set1.cartesian_product(set2)
            print("Cartesian product of Set 1 and Set 2:", cartesian_product_set.elements)

        elif choice == "0":
            print("Exiting the program.")
            break

        else:
            print("Invalid choice. Please try again.")


# Run the main program
main()
