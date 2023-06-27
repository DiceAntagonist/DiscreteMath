class Relation:
    def __init__(self, matrix):
        self.matrix = matrix
        self.size = len(matrix)

    def is_reflexive(self):
        for i in range(self.size):
            if not self.matrix[i][i]:
                return False
        return True

    def is_symmetric(self):
        for i in range(self.size):
            for j in range(self.size):
                if self.matrix[i][j] != self.matrix[j][i]:
                    return False
        return True

    def is_anti_symmetric(self):
        for i in range(self.size):
            for j in range(self.size):
                if self.matrix[i][j] and self.matrix[j][i] and i != j:
                    return False
        return True

    def is_transitive(self):
        for i in range(self.size):
            for j in range(self.size):
                if self.matrix[i][j]:
                    for k in range(self.size):
                        if self.matrix[j][k] and not self.matrix[i][k]:
                            return False
        return True

    def classify_relation(self):
        is_equivalence = self.is_reflexive() and self.is_symmetric() and self.is_transitive()
        is_partial_order = self.is_reflexive() and self.is_anti_symmetric() and self.is_transitive()

        if is_equivalence:
            return "Equivalence relation"
        elif is_partial_order:
            return "Partial order relation"
        else:
            return "None"

# Example usage:
matrix = [[1, 0, 1],
          [0, 1, 0],
          [1, 0, 1]]

relation = Relation(matrix)
classification = relation.classify_relation()
print(classification)
