def minimum_transportation_price(
    suppliers: list[int], consumers: list[int], costs: list[list[int]]
):
    """Notes
    Costs-matrix legend: costs[i][j] is the cost of transporting 1 unit of produce from suppliers[i] to consumers[j]

    The produce is identical - multiple suppliers can be the source for one consumer, and multiple consumers can be the target of one supplier

    The produce is not important - it can be anything and have any price, we're only interested in transporting it efficiently

    Total supply will always equal total demand

    Your solution should pass 12 cases with matrices of size 150x150 as a performance test (the reference solution itself takes ~8500 ms to do so)
    """
    # we map suppliers to rows in costs
    # we map consumers to cols in costs
    cost_row_limit: int = len(suppliers)
    cost_col_limit: int = len(consumers)
    row_penalties: list[int] = list()
    col_penalties: list[int] = list()
    for row in costs:
        arranged = sorted(row)
        diff = arranged[1] - arranged[0]
        row_penalties.append(diff)
    for i in range(cost_col_limit):
        col = [row[i] for row in costs]
        arranged = sorted(col)
        diff = arranged[1] - arranged[0]
        col_penalties.append(diff)
    max_row_item = max(row_penalties)
    max_col_item = max(col_penalties)
    if max_row_item > max_col_item:
        to_remove = row_penalties.index(max(row_penalties))
        row_index_to_reduce = costs[to_remove].index(min(costs[to_remove]))
        supply_to_check = suppliers[to_remove]
        demand_to_reduce = consumers[row_index_to_reduce]
        print(
            f"{to_remove=} {row_index_to_reduce=} {supply_to_check=} {demand_to_reduce=}"
        )
    else:
        to_remove = col_penalties.index(max(col_penalties))
        cols = [row[to_remove] for row in costs]
        row_index_to_reduce = cols.index(min(cols))
        supply_to_check = suppliers[row_index_to_reduce]
        demand_to_reduce = consumers[to_remove]
    return


if __name__ == "__main__":
    suppliers = [10, 7, 13]
    consumers = [6, 20, 4]
    costs = [[4, 12, 3], [20, 1, 6], [7, 0, 5]]
    minimum_transportation_price(suppliers, consumers, costs)
