#!/usr/bin/python


import re


def  findPotentialInsiderTraders(datafeed):
    buyers = []
    b_prices = []
    b_amounts=[]


    sellers = []
    s_prices = []
    s_amounts = []

    prices = []

    b_incomes = []

    winner = []

    cur_price = 0
    for line in datafeed:
        fields = line.split('|')

        
        if(len(fields)==1):
            num_line = fields[0]
        elif(len(fields)==2):
            day = fields[0]
            pre_price = cur_price
            cur_price = int(fields[1])
            prices.append(cur_price)

        elif(len(fields)==4):
            day = fields[0]
            name = fields[1]
            trade = fields[2]
            amount = fields[3]

            if(trade=='BUY'):
                buyers.append(day+'|'+name)
                b_amounts.append(int(amount))
                b_prices.append(int(amount)*int(cur_price))


            elif(trade =='SELL'):
                sellers.append(day+'|'+name)
                s_amounts.append(int(amount))
                s_prices.append(int(amount)*int(cur_price))


            if(pre_price!=cur_price & pre_price!=0):
                for i in range(len(b_amounts)):
                    if(b_amounts[i]*cur_price-b_prices[i]>500000):
                        if(winner.count(buyers[i])==0):
                            winner.append(buyers[i])

                for i in range(len(s_amounts)):
                    for p in prices:
                        if(s_prices[i] - s_amounts[i]*p>500000):
                            if(winner.count(sellers[i])==0):
                                winner.append(sellers[i])

            
        else:
            continue



    print(prices)

    print(winner)



    #print("%d %d"%(day, price))

    return 0



if __name__ == '__main__':

    filename="input"

    F = open(filename)
    datafeed= []
    for line in F:
        line = line.strip('\n')
        datafeed.append(line)


    findPotentialInsiderTraders(datafeed)

