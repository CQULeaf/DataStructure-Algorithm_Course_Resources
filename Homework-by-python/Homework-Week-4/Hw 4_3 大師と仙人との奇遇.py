import heapq

def calculate_profit(N, prices):
    # Using a list to represent the min-heap for bought stock prices
    bought_prices = []
    # Total profit made
    total_profit = 0

    for i in range(N):
        # Buy a stock every day
        heapq.heappush(bought_prices, prices[i])

        # If it's not the last day, check if there are any stocks to sell
        if i != N - 1:
            # Check the stock with the lowest purchase price
            while bought_prices and bought_prices[0] < prices[i + 1]:
                # Update the total profit by selling the stock
                total_profit += prices[i + 1] - heapq.heappop(bought_prices)
        
        # On the last day, sell all remaining stocks in hand
        else:
            while bought_prices:
                total_profit += prices[i] - heapq.heappop(bought_prices)

    return total_profit

# Input
N = int(input())
prices = list(map(int, input().split()))

# Output
print(calculate_profit(N, prices))
