./tmp > inp.txt
python3 BiladerimIcin.py < inp.txt > oup1.txt
./BiladerimIcin < inp.txt > oup2.txt
diff oup1.txt oup2.txt
