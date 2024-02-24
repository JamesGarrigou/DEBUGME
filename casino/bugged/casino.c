/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casino.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarrigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:10:04 by rgarrigo          #+#    #+#             */
/*   Updated: 2024/02/24 18:18:59 by rgarrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

/*	My submition to https://codeforces.com/contest/1929/problem/C =D
	But the verdict is "Wrong compilation" x(
	I don't get it, it's frustrating!

The subject:
	C. Sasha and the Casino
	time limit per test
	2 seconds
	memory limit per test
	256 megabytes
	input
	standard input
	output
	standard output

	Sasha decided to give his girlfriend the best handbag, but unfortunately
	for Sasha, it is very expensive. Therefore, Sasha wants to earn it. After
	looking at earning tips on the internet, he decided to go to the casino.

	Sasha knows that the casino operates under the following rules. If Sasha
	places a bet of y coins (where y is a positive integer), then in case of
	winning, he will receive y⋅k coins (i.e., his number of coins will increase
	by y⋅(k−1)). And in case of losing, he will lose the entire bet amount
	(i.e., his number of coins will decrease by y).

	Note that the bet amount must always be a positive (>0) integer and cannot
	exceed Sasha's current number of coins.

	Sasha also knows that there is a promotion at the casino: he cannot lose
	more than x times in a row.

	Initially, Sasha has a coins. He wonders whether he can place bets such
	that he is guaranteed to win any number of coins. In other words, is it true
	that for any integer n, Sasha can make bets so that for any outcome that
	does not contradict the rules described above, at some moment of time he
	will have at least n coins.

	Input
	Each test consists of multiple test cases. The first line contains a single
	integer t (1≤t≤1000) — the number of test cases. The description of the test
	cases follows.

	The single line of each test case contains three integers k,x and a
	(2≤k≤30, 1≤x≤100, 1≤a≤109) — the number of times the bet is increased in
	case of a win, the maximum number of consecutive losses, and the initial
	number of coins Sasha has.

	Output
	For each test case, output "YES" (without quotes) if Sasha can achieve it
	and "NO" (without quotes) otherwise.

	You can output "YES" and "NO" in any case (for example, the strings "yEs",
	"yes" and "Yes" will be recognized as a positive answer).

	Example

	Input
	9
	2 1 7
	2 1 1
	2 3 15
	3 3 6
	4 4 5
	5 4 7
	4 88 1000000000
	25 69 231
	13 97 18806

	Output
	YES
	NO
	YES
	NO
	NO
	YES
	NO
	NO
	NO

	Note
	In the first test case, Sasha can proceed as follows:

		- If Sasha places a bet for the first time or if he won the previous
		bet, then he places 1 coin.
		- If Sasha lost the previous bet, then he places 2 coins.

	Note that Sasha cannot lose more than once in a row.

	It can be proven that with this strategy, Sasha can obtain as many coins as
	he wants.

	In the second test case, Sasha can only place 1 coin for the first time. But
	in case of a loss, he will not be able to place any more bets, so he will
	not be able to guarantee having as many coins as he wants.
*/

void	solve(void)
{
	int			k;
	int			x;
	int			a;
	long long	total;
	long long	bet;

	scanf("%d%d%d", &k, &x, &a);
	++x;
	total = 0;
	bet = 1;
	while (x--)
	{
		total += bet;
		if (total > a)
		{
			pritnf("NO\n");
			return ;
		}
		bet = total / (k - 1) + 1;
	}
	printf("YES\n");
}

int	main(void)
{
	int	t;

	scanf("%d", &t);
	while (t--)
		solve();
	return (0);
}
