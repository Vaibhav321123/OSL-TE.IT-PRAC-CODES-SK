#! /bin/bash
opt=1
while [ "$opt" -lt 6 ]
do

    printf "1. Create Address Book\n2. View Records\n3 .Insert new Record\n4. Delete a Record\n5. Modify a Record\n6. Exit\n\n"
    
    read opt
    case $opt in

    1)
        printf "Enter filename : "
        read fileName
        if [ -e $fileName ] ; 
        then
            rm $fileName
        fi
        cont=1
        printf  "NAME\t\tNUMBER\t\t\tADDRESS\n=====================================\n" | cat >> $fileName
        while [ "$cont" -gt 0 ]
        do
            printf "\nEnter Name : "
            read name
            printf "Enter Phone Number of  $name"
            read number
            printf "Enter Address of  $name"
            read address
            printf "$name\t$number\t\t$address\n" | cat >> $fileName
            printf "Enter 0 to Stop, 1 to Enter next :"
            read cont
        done
        ;;
    2)
        cat $fileName
        ;;
    3)
        printf "\nEnter Name : "
        read name
        printf "Enter Phone Number of  $name"
        read number
        printf "Enter Address of  $name"
        read address
        printf "$name\t$number\t\t$address\n" | cat >> $fileName
        ;;
    4)
        printf "Delete record\nEnter Name/Phone Number"
        read pattern
        temp="temp"
        grep -v $pattern $fileName | cat >> $temp 
        rm $fileName
        cat $temp | cat >> $fileName
        rm $temp
        ;;
    5)
        printf "Modify record\nEnter Name/Phone Number"
        read pattern
        temp="temp"
        grep -v $pattern $fileName | cat >> $temp
        rm $fileName
        cat $temp | cat >> $fileName
        rm $temp
        printf "Enter Name"
        read name
        printf "Enter Phone Number of $name"
        read number
        printf "Enter Address of $name"
        read address
        echo -e "$name\t$number\t\t$address\n" | cat >> $fileName
        ;;
    esac
done


OUTPUT:
1. Create Address Book
2. View Records
3 .Insert new Record
4. Delete a Record
5. Modify a Record
6. Exit

1
Enter filename : Address

Enter Name : Shreeraj Shinde
Enter Phone Number of  Shreeraj Shinde9827193890
Enter Address of  Shreeraj ShindeShaniwaar Peth, Pune
Enter 0 to Stop, 1 to Enter next :1

Enter Name : Kanak Gambhirrao
Enter Phone Number of  Kanak Gambhirrao9809818379
Enter Address of  Kanak GambhirraoShaniwaar Peth, Pune
Enter 0 to Stop, 1 to Enter next :1

Enter Name : Dhruv Dhapate
Enter Phone Number of  Dhruv Dhapate9820387461
Enter Address of  Dhruv DhapateBaner, Pune
Enter 0 to Stop, 1 to Enter next :0
1. Create Address Book
2. View Records
3 .Insert new Record
4. Delete a Record
5. Modify a Record
6. Exit

2
NAME            NUMBER                  ADDRESS
=====================================================================
Shreeraj Shinde 9827193890              Shaniwaar Peth, Pune
Kanak Gambhirrao        9809818379              Shaniwaar Peth, Pune
Dhruv Dhapate   9820387461              Baner, Pune
1. Create Address Book
2. View Records
3 .Insert new Record
4. Delete a Record
5. Modify a Record
6. Exit

3

Enter Name : Tanaya Morgaonkar
Enter Phone Number of  Tanaya Morgaonkar8790987639
Enter Address of  Tanaya MorgaonkarPune
1. Create Address Book
2. View Records
3 .Insert new Record
4. Delete a Record
5. Modify a Record
6. Exit

2
NAME            NUMBER                  ADDRESS
=====================================================================
Shreeraj Shinde 9827193890              Shaniwaar Peth, Pune
Kanak Gambhirrao        9809818379              Shaniwaar Peth, Pune
Dhruv Dhapate   9820387461              Baner, Pune
Tanaya Morgaonkar       8790987639              Pune
1. Create Address Book
2. View Records
3 .Insert new Record
4. Delete a Record
5. Modify a Record
6. Exit

4
Delete record
Enter Name/Phone NumberShreeraj Shinde
grep: Shinde: No such file or directory
1. Create Address Book
2. View Records
3 .Insert new Record
4. Delete a Record
5. Modify a Record
6. Exit

2
Address:NAME            NUMBER                  ADDRESS
Address:=====================================================================
Address:Kanak Gambhirrao        9809818379              Shaniwaar Peth, Pune
Address:Dhruv Dhapate   9820387461              Baner, Pune
Address:Tanaya Morgaonkar       8790987639              Pune
1. Create Address Book
2. View Records
3 .Insert new Record
4. Delete a Record
5. Modify a Record
6. Exit

5
Modify record
Enter Name/Phone NumberDhruv
Enter NameDhruv Dhapate
Enter Phone Number of Dhruv Dhapate8982910283
Enter Address of Dhruv DhapateSomwaar Peth, Pune
1. Create Address Book
2. View Records
3 .Insert new Record
4. Delete a Record
5. Modify a Record
6. Exit

2
NAME            NUMBER                  ADDRESS
=====================================================================
Kanak Gambhirrao        9809818379              Shaniwaar Peth, Pune
Tanaya Morgaonkar       8790987639              Pune
-e Dhruv Dhapate        8982910283              Somwaar Peth, Pune

1. Create Address Book
2. View Records
3 .Insert new Record
4. Delete a Record
5. Modify a Record
6. Exit

6
