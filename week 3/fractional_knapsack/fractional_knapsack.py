# Uses python3
import sys

def get_optimal_value(capacity, weights, values):
    value = 0.

    def get_max_value_index():
        index = None
        value = 0
        for (i, v) in enumerate(values):
            if weights[i] != 0 and v / weights[i] > value:
                index = i
                value = v / weights[i]
        return index

    # there are three possible cases for the knapsack:
    # 1. the knapsack has same capacity as the loot
    # 2. the knapsack has smaller capacity than the loot
    # 3. the knapsack has greater capacity than the loot

    item_index = get_max_value_index()
    while capacity != 0 and item_index is not None: # handles case 3
        if capacity >= weights[item_index]: # handles case 1 and 3
            capacity -= weights[item_index]
            value += values[item_index]
            weights[item_index] = 0
        else: # handles case 2
            value += (values[item_index] * 1.0 / weights[item_index]) * capacity
            capacity = 0
            break
        item_index = get_max_value_index()

    return value

def test_solution():
    assert get_optimal_value(50, [20, 50, 30], [60, 100, 120]) == 180
    assert get_optimal_value(50, [30], [500]) == 500
    assert '%.4f' % round(get_optimal_value(10, [30], [500]), 4) == '%.4f' % round(500.0 / 3, 4)

if __name__ == "__main__":
    test_solution()
