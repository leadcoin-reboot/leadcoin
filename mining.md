---
layout: page
title: Mining
permalink: /mining/
weight: 2
---

#What is "mining" ?

In simple terms, all the LeadCoin clients have a say on the operation of the LeadCoin network. The network ensures that counterfeiting and ‘double spending’ is not possible. All transactions are placed in a publicly viewable ledger called a block chain. The network gives cryptographic work to the miners to attempt to solve a block – the candidate for the next block on the chain. The more work (Hashes) a miner can do the better it’s chance of being the winner of the block. The wallet associated with the block winner receives the amount of coins that the network is currently allocating to block winners. This is  480 LeadCoins currently. The winning block will be affirmed by the network after 100 or so subsequent blocks have been produced. The network ensures that, on average, only 1 block is produced every 30 seconds. This is why the more total mining power there is on a network the harder it gets to ‘find’ a block.

#Two ways of mining
LeadCoin can be mined in two ways: Pool mining or Solo mining.

Solo mining is where the wallet itself is set to mine or the wallet is configured to be mined against by another program (Dedicated Miner). Solo miners tend to use dedicated mining programs since it is easier to fine tune these for specific computers. Mining programs include Minerd (CPU), CGMiner (Graphics Card), CUDAMiner (Graphics Card).

#Solo mining
- Download and install wallet

- Edit leadcoin.conf as so:
{% highlight text %}
rpcuser=leadcoinrpc
rpcpassword=yourPassword
rpcport=27771
listen=1
server=1

addnode=107.170.118.16
addnode=23.227.161.165
addnode=86.115.80.237
addnode=46.165.208.136
addnode=46.201.244.109
addnode=80.229.249.107
addnode=128.73.126.243
addnode=144.76.100.197
addnode=107.170.71.190
addnode=213.21.33.12
addnode=50.197.11.193
{% endhighlight %}
Change user and password to preffered values

- Next, download the CGMiner. Note this has to be version 3.7.2 or less.

cgminer-3.7.2-mp-0.04.zip
Again, it will normally be downloaded into your ‘Downloads’ folder and so will need to be ‘unzipped’ into your choice of location. Also it is a good idea to make a short-cut to the cgminer.exe which can then be used to add command line options when running the file. The command line in the shorcut properties will look something like this, below;

C:\Users\jimc\documents\cgminer-3.7.2-windows\cgminer.exe –scrypt -o 127.0.0.1:27771 -u jimc.1 -p pass
When running this you should get a DOS window showing various info including a hash rate – like 211KHs.
Congratulations! You are mining LeadCoin! Every so often you will ‘win’ a block and receive coins into your wallet!

![cgminer](/assets/images/cg-miner-leadcoin.png "CgMiner")



#Mining in pool
The official LeadCoin pools are:

#####[ComradePool’s LeadCoin Pool](http://comradepool.com:9500)
You don’t need to sign in to this pool, just use your wallet address as username:
{% highlight text %}
cgminer --scrypt -o comradepool.com:9500 -u yourWalletAddress -p x
{% endhighlight %}
