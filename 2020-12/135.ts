function candy(ratings: number[]): number 
    // 暴力算法，CPP 会超时
    let n: number = ratings.length;
    let candies: number[] = new Array(n).fill(1);

    for (let i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1])
            candies[i] = candies[i - 1] + 1;
        let j = i;
        while (j > 0 && ratings[j] < ratings[j - 1] && candies[j] == candies[j - 1]) {
            candies[j - 1]++;
            j--;
        }
    }

    return candies.reduce((a, c) => a + c, 0);
};