def find_equation_solutions(n, C):
    solutions = []
    equation_solution = [0] * n

    def generate_solution(index, remaining_sum):
        if index == n:
            if remaining_sum == 0:
                solutions.append(list(equation_solution))
            return

        for x in range(remaining_sum + 1):
            equation_solution[index] = x
            generate_solution(index + 1, remaining_sum - x)

    generate_solution(0, C)
    return solutions

n = 4
C = 6

solutions = find_equation_solutions(n, C)

print(f"All solutions for x1 + x2 + x3 + ... + xn = {C} where n = {n}:")
for solution in solutions:
    print(solution)
