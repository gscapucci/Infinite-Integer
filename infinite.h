#ifndef INFINITE_H
#define INFINITE_H

#include "Timer.h"

#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <chrono>

class Infinite{
    std::vector<int8_t> val;
    bool positive;
    friend std::ostream& operator<<(std::ostream& os, const Infinite& inf);
    friend std::istream& operator>>(std::istream& os, Infinite& inf);
    void removeLeadingZeros();
    void fromString(const std::string& str);
public:
    //constructors//
    Infinite();
    Infinite(const char* c);
    Infinite(const std::string& s);
    Infinite(int i);
    Infinite(long l);
    Infinite(long long ll);
    Infinite(unsigned int ui);
    Infinite(unsigned long ul);
    Infinite(unsigned long long ull);
    Infinite(const Infinite& I);

    //assignment operators//
    const Infinite& operator=(const char* c);
    const Infinite& operator=(const std::string& s);
    const Infinite& operator=(int i);
    const Infinite& operator=(long l);
    const Infinite& operator=(long long ll);
    const Infinite& operator=(unsigned int ui);
    const Infinite& operator=(unsigned long ul);
    const Infinite& operator=(unsigned long long ull);
    const Infinite& operator=(const Infinite& I);

    //increment operators//
    const Infinite& operator++();
    const Infinite operator++(int);
    const Infinite& operator--();
    const Infinite operator--(int);

    //assignment-operational operators//

    const Infinite& operator+=(const Infinite& I);
    const Infinite& operator-=(const Infinite& I);
    const Infinite& operator*=(const Infinite& I);
    const Infinite& operator/=(const Infinite& I);//remake
    const Infinite& operator%=(const Infinite& I);//to do


    //operational operators//
    Infinite operator-();
    Infinite operator+(const Infinite& I);
    Infinite operator-(const Infinite& I);
    Infinite operator*(const Infinite& I);
    Infinite operator/(const Infinite& I);//to do
    Infinite operator%(const Infinite& I);//to do

    //comparission operators//
    const bool operator==(const Infinite& I) const;
    const bool operator!=(const Infinite& I) const;
    const bool operator<(const Infinite& I) const;
    const bool operator>(const Infinite& I) const;
    const bool operator<=(const Infinite& I) const;
    const bool operator>=(const Infinite& I) const;

    //conversion functions//
    std::string toString() const;
    template<typename T>
    T toIntegerType() const;
    //size functions/
    long long size() const;//size in bytes
    long long numberOfDigits() const;
    long long maxSize() const;//max number of digits
};

void Infinite::removeLeadingZeros()
{
    for (int i = val.size() - 1; i > 0; i--)
    {
        if(val[i] != 0)
        {
            return;
        }
        else
        {
            val.pop_back();
        }
    }
}

void Infinite::fromString(const std::string& str)
{
    positive = true;
    val.clear();
    int i = 0;
    if(str[0] == '-')
    {
        i = 1;
    }
    for(int j = str.length() - 1;j >= i; j--)
    {
        val.push_back((int)(str[j] - '0'));
    }
    removeLeadingZeros();
}

Infinite::Infinite()
:positive(true), val({0})
{
}

Infinite::Infinite(const char* c)
{
    long long j = 0;
    positive = true;
    if(c[0] == '-')
    {
        positive = false;
        j++;
    }
    std::string s(c);
    for(long long i = s.length() - 1; i >= j; i--)
    {
        val.push_back((int)(s[i] - '0'));
    }
    removeLeadingZeros();
}

Infinite::Infinite(const std::string& s)
{
    long long j = 0;
    positive = true;
    if(s[0] == '-')
    {
        positive = false;
        j++;
    }
    for(long long i = s.length() - 1; i >= j ; i--)
    {
        val.push_back((int)(s[i] - '0'));
    }
    removeLeadingZeros();
}

Infinite::Infinite(int i)
{
    positive = true;
    int pos = 0;
    if(i < 0)
    {
        pos++;
        positive = false;
    }
    
    std::string str = std::to_string(i);
    for (long long j = str.length() - 1; j >= pos; j--)
    {
        val.push_back((int)(str[j] - '0'));
    }
    removeLeadingZeros();
}

Infinite::Infinite(long l)
{
    positive = true;
    int pos = 0;
    if(l < 0)
    {
        pos++;
        positive = false;
    }
    std::string str = std::to_string(l);
    for (long long i = str.length() - 1; i >= pos; i--)
    {
        val.push_back((int)(str[i] - '0'));
    }
    removeLeadingZeros();
}

Infinite::Infinite(long long ll)
{
    positive = true;
    int pos = 0;
    if(ll < 0)
    {
        pos++;
        positive = false;
    }
    std::string str = std::to_string(ll);
    for (long long i = str.length() - 1; i >= pos; i--)
    {
        val.push_back((int)(str[i] - '0'));
    }
    removeLeadingZeros();
}
Infinite::Infinite(unsigned int ui)
{
    positive = true;
    std::string str = std::to_string(ui);
    for (long long i = str.length() - 1; i >= 0; i--)
    {
        val.push_back((int)(str[i] - '0'));
    }
    removeLeadingZeros();
}
Infinite::Infinite(unsigned long ul)
{
    positive = true;
    std::string str = std::to_string(ul);
    for (long long i = str.length() - 1; i >= 0; i--)
    {
        val.push_back((int)(str[i] - '0'));
    }
    removeLeadingZeros();
}

Infinite::Infinite(unsigned long long ull)
{
    positive = true;
    std::string str = std::to_string(ull);
    for (long long i = str.length() - 1; i >= 0; i--)
    {
        val.push_back((int)(str[i] - '0'));
    }
    removeLeadingZeros();
}

Infinite::Infinite(const Infinite& I)
    :val(I.val), positive(I.positive)
{
}


const Infinite& Infinite::operator=(const char* c)
{
    positive = true;
    val.clear();
    long long j = 0;
    if(c[0] == '-')
    {
        positive = false;
        j++;
    }
    std::string s(c);
    for(long long i = s.length() - 1; i >= j; i--)
    {
        val.push_back((int)(s[i] - '0'));
    }
    removeLeadingZeros();
    return *this;
    
}

const Infinite& Infinite::operator=(const std::string& s)
{
    positive = true;
    val.clear();
    long long j = 0;
    if(s[0] == '-')
    {
        positive = false;
        j++;
    }
    for(long long i = s.length() - 1; i >= j ; i--)
    {
        val.push_back((int)(s[i] - '0'));
    }
    removeLeadingZeros();
    return *this;
}

const Infinite& Infinite::operator=(int i)
{
    positive = true;
    val.clear();
    int pos = 0;
    if(i < 0)
    {
        pos++;
        positive = false;
    }
    std::string str = std::to_string(i);
    for (long long j = str.length() - 1; j >= pos; j--)
    {
        val.push_back((int)(str[j] - '0'));
    }
    removeLeadingZeros();
    return *this;
}

const Infinite& Infinite::operator=(long l)
{
    positive = true;
    val.clear();
    int pos = 0;
    if(l < 0)
    {
        pos++;
        l = labs(l);
        positive = false;
    }
    std::string str = std::to_string(l);
    for (long long i = str.length() - 1; i >= pos; i--)
    {
        val.push_back((int)(str[i] - '0'));
    }
    removeLeadingZeros();
    return *this;
}

const Infinite& Infinite::operator=(long long ll)
{
    positive = true;
    val.clear();
    int pos = 0;
    if(ll < 0)
    {
        pos++;
        positive = false;
    }
    std::string str = std::to_string(ll);
    for (long long i = str.length() - 1; i >= pos; i--)
    {
        val.push_back((int)(str[i] - '0'));
    }
    removeLeadingZeros();
    return *this;
}

const Infinite& Infinite::operator=(unsigned int ui)
{
    positive = true;
    val.clear();
    std::string str = std::to_string(ui);
    for (long long i = str.length() - 1; i >= 0; i--)
    {
        val.push_back((int)(str[i] - '0'));
    }
    removeLeadingZeros();
    return *this;
}

const Infinite& Infinite::operator=(unsigned long ul)
{
    positive = true;
    val.clear();
    std::string str = std::to_string(ul);
    for (long long i = str.length() - 1; i >= 0; i--)
    {
        val.push_back((int)(str[i] - '0'));
    }
    removeLeadingZeros();
    return *this;
}

const Infinite& Infinite::operator=(unsigned long long ull)
{
    positive = true;
    val.clear();
    std::string str = std::to_string(ull);
    for (long long i = str.length() - 1; i >= 0; i--)
    {
        val.push_back((int)(str[i] - '0'));
    }
    removeLeadingZeros();
    return *this;
}

const Infinite& Infinite::operator=(const Infinite& I)
{
    std::string str(I.toString());
    fromString(str);
    return *this;
}

const Infinite& Infinite::operator++()
{
    long long index = 0;
    val[index] += positive ? 1 : -1;
    while (val[index] > 9)
    {
        div_t myDiv = div(val[index], 10);

        val[index] = myDiv.rem;

        if(val.size() == index + 1)
        {
            val.push_back(myDiv.quot);
        }
        else
        {
            index++;
            val[index]++;
        }
    }
    while (val[index] < 0)
    {
        if(val.size() == 1)
        {
            positive = false;
            val[index] = 1;
        }
        else
        {
            val[index] = 9;
            index++;
            val[index]--;
        }
        removeLeadingZeros();
    }
    return *this;
}

const Infinite Infinite::operator++(int)
{
    Infinite copy = *this;
    this->operator++();
    return copy;
}

const Infinite& Infinite::operator--()
{
    long long index = 0;
    val[index] += positive ? -1 : 1;
    while (val[index] > 9)
    {
        div_t myDiv = div(val[index], 10);

        val[index] = myDiv.rem;

        if(val.size() == index + 1)
        {
            val.push_back(myDiv.quot);
        }
        else
        {
            index++;
            val[index]++;
        }
    }
    while (val[index] < 0)
    {
        if(val.size() == 1)
        {
            positive = false;
            val[index] = 1;
        }
        else
        {
            val[index] = 9;
            index++;
            val[index]--;
        }
        removeLeadingZeros();
    }
    return *this;
}

const Infinite Infinite::operator--(int)
{
    Infinite copy = *this;
    this->operator--();
    return copy;
}

const Infinite& Infinite::operator+=(const Infinite& I)
{
    long long size = I.val.size(), diff = val.capacity();

    val.reserve(I.val.size() > val.size() ? I.val.size() : val.size());
    diff -= val.capacity();
    if(diff != 0)
    {
        while (diff != 0)
        {
            val.push_back(0);
            diff--;
        }
    }
    if(positive == I.positive)
    {

        for (long long i = 0; i < size; i++)
        {
            val[i] += I.val[i];
            long long index = i;
            while (val[index] > 9)
            {
                div_t myDiv = div(val[index], 10);
                val[index] = myDiv.rem;
                if(val.size() == index + 1)
                {
                    val.push_back(myDiv.quot);
                }
                else
                {
                    index++;
                    val[index] += myDiv.quot;
                }
            }
        }
    }
    else
    {
        if(val.size() == I.val.size())
        {
            for (long long i = size - 1; i >= 0; i--)
            {
                if(I.val[i] > val[i])
                {
                    positive = !positive;
                    break;
                }
            }
        }
        
        for (long long i = 0; i < size; i++)
        {
            val[i] -= I.val[i];
            if(val[i] < 0)
            {
                long long index = i;
                val[index] = 10 - I.val[index];
                index++;
                val[index]--;
                while (val[index] < 0)
                {
                    val[index] = 10 + val[index];
                    index++;
                    val[index]--;
                }
            }
            removeLeadingZeros();
        }
    }
    return *this;
}

const Infinite& Infinite::operator-=(const Infinite& I)
{
    long long size = I.val.size(), diff = val.capacity();

    val.reserve(I.val.size() > val.size() ? I.val.size() : val.size());
    diff -= val.capacity();
    while (diff != 0)
    {
        val.push_back(0);
        diff++;
    }
    if(positive != I.positive)
    {
        for (long long i = 0; i < size; i++)
        {
            val[i] += I.val[i];
            long long index = i;
            while (val[index] > 9)
            {
                div_t myDiv = div(val[index], 10);
                val[index] = myDiv.rem;
                if(val.size() == index + 1)
                {
                    val.push_back(myDiv.quot);
                }
                else
                {
                    index++;
                    val[index] += myDiv.quot;
                }
            }
        }
    }
    else
    {
        if(val.size() == I.val.size())
        {
            for (long long i = size - 1; i >= 0; i--)
            {
                if(I.val[i] > val[i])
                {
                    positive = !positive;
                    break;
                }
            }
        }

        for (long long i = 0; i < size; i++)
        {
            val[i] -= I.val[i];
            if(val[i] < 0)
            {
                long long index = i;
                val[index] = 10 - I.val[index];
                index++;
                val[index]--;
                while (val[index] < 0)
                {
                    val[index] = 10 + val[index];
                    index++;
                    val[index]--;
                }
            }
        }
    }
    removeLeadingZeros();
    return *this;
}

const Infinite& Infinite::operator*=(const Infinite& I)
{
    Timer t;
    long long size, diff, initSize, ISize;
    std::vector<int8_t> sum;

    size = val.size() + I.val.size();
    diff = val.size() - size;
    initSize = val.size();
    ISize = I.val.size();

    val.reserve(size);

    while (diff != 0)
    {
        val.push_back(0);
        diff++;
    }

    while (sum.size() < val.size())
    {
        sum.push_back(0);
    }
    
    if(I.positive == false)
    {
        positive = !positive;
    }

    for (long long i = 0; i < initSize; i++){
        for (long long j = 0; j < ISize; j++)
        {
            int aux = val[i] * I.val[j];
            if(aux > 9)
            {
                long long index = i + j;
                div_t myDiv = div(aux, 10);
                aux = myDiv.rem;
                sum[index + 1] += myDiv.quot;
            }
            sum[i + j] += aux;
            while(sum[i + j] > 9)
            {
                long long index = i + j;
                div_t myDiv = div(sum[index], 10);
                sum[index] = myDiv.rem;
                index++;
                sum[index] += myDiv.quot;
            }
        }
    }
    this->val = sum;
    removeLeadingZeros();
    return *this;
}

const Infinite& Infinite::operator/=(const Infinite& I)
{
    if(I.val.size() == 1 && I.val[0] == 0)
    {
        std::cout << "is not possible divide by 0." << std::endl;
        return *this;
    }
    if(val.size() < I.val.size())
    {
        std::vector<int8_t> vec{0};
        positive = true;
        val = vec;
        return *this;
    }
    else if(val.size() == I.val.size())
    {
        for (long long i = 0; i < val.size(); i++)
        {
            if(I.val[i] < val[i])
            {
                break;
            }
            if(I.val[i] > val[i])
            {
                std::vector<int8_t> vec{0};
                positive = true;
                val = vec;
                return *this;
            }
        }
    }
    if(I.positive == false)
    {
        positive = !positive;
    }


    
    return *this;
}

// const Infinite& Infinite::operator%=(const Infinite& I)
// {
//     if((I.size() == 1 && I.val[0] == 0) || val.size() < I.val.size())
//     {
//         return *this;
//     }

// }
Infinite Infinite::operator-()
{
    Infinite result = *this;
    result.positive = !positive;
    return result;
}
Infinite Infinite::operator+(const Infinite& I)
{
    std::vector<int8_t> result;
    bool resultPositive = positive;
    long long size = I.val.size(), diff = val.capacity();

    val.reserve(I.val.size() > val.size() ? I.val.size() : val.size());
    diff -= val.capacity();
    while (diff != 0)
    {
        val.push_back(0);
        diff++;
    }
    if(positive == I.positive)
    {
        long long carry = 0;
        for (long long i = 0; i < size; i++)
        {
            result.push_back(val[i] + I.val[i] + carry);
            carry = 0;
            while (result[i] > 9)
            {
                div_t myDiv = div(result[i], 10);
                result[i] = myDiv.rem;
                carry = myDiv.quot;
            }
        }
        if(carry != 0)
        {
            result.push_back(carry);
        }
    }
    else
    {
        if(val.size() == I.val.size())
        {
            for (long long i = size - 1; i >= 0; i--)
            {
                if(I.val[i] > val[i])
                {
                    resultPositive = !resultPositive;
                    break;
                }
            }
        }
        
        for (long long i = 0; i < size; i++)
        {
            result.push_back(val[i] - I.val[i]);
            if(val[i] < 0)
            {
                long long index = i;
                result[index] = 10 - I.val[index];
                index++;
                if(index == result.size())
                    result.push_back(0);
                result[index] = val[index] - 1;
                while (result[index] < 0)
                {
                    result[index] = 10 + val[index];
                    index++;
                    if(index == val.size())
                        result.push_back(0);
                    result[index] = val[index] - 1;
                }
            }
            removeLeadingZeros();
        }
    }
    Infinite res;
    res.val = result;
    res.positive = resultPositive;
    res.removeLeadingZeros();
    return res;
}

Infinite Infinite::operator-(const Infinite& I)
{
    std::vector<int8_t> result;
    bool resultPositive = positive;
    long long size = I.val.size(), diff = val.capacity();

    val.reserve(I.val.size() > val.size() ? I.val.size() : val.size());
    diff -= val.capacity();
    while (diff != 0)
    {
        val.push_back(0);
        diff++;
    }
    if(positive != I.positive)
    {
        long long carry = 0;
        for (long long i = 0; i < size; i++)
        {
            result.push_back(val[i] + I.val[i] + carry);
            carry = 0;
            while (result[i] > 9)
            {
                div_t myDiv = div(result[i], 10);
                result[i] = myDiv.rem;
                carry = myDiv.quot;
            }
        }
        if(carry != 0)
        {
            result.push_back(carry);
        }
    }
    else
    {
        if(val.size() == I.val.size())
        {
            for (long long i = size - 1; i >= 0; i--)
            {
                if(I.val[i] > val[i])
                {
                    resultPositive = !resultPositive;
                    break;
                }
            }
        }
        
        for (long long i = 0; i < size; i++)
        {
            result.push_back(val[i] - I.val[i]);
            if(val[i] < 0)
            {
                long long index = i;
                result[index] = 10 - I.val[index];
                index++;
                if(index == result.size())
                    result.push_back(0);
                result[index] = val[index] - 1;
                while (result[index] < 0)
                {
                    result[index] = 10 + val[index];
                    index++;
                    if(index == val.size())
                        result.push_back(0);
                    result[index] = val[index] - 1;
                }
            }
            removeLeadingZeros();
        }
    }
    Infinite res;
    res.val = result;
    res.positive = resultPositive;
    res.removeLeadingZeros();
    return res;
}

Infinite Infinite::operator*(const Infinite& I)
{
    long long size, diff, initSize, ISize;
    std::vector<int8_t> sum;
    bool pos = positive;
    size = val.size() + I.val.size();
    diff = val.size() - size;
    initSize = val.size();
    ISize = I.val.size();

    val.reserve(size);

    while (diff != 0)
    {
        val.push_back(0);
        diff++;
    }

    while (sum.size() < val.size())
    {
        sum.push_back(0);
    }
    
    if(I.positive == false)
    {
        pos = !pos;
    }

    for (long long i = 0; i < initSize; i++){
        for (long long j = 0; j < ISize; j++)
        {
            int aux = val[i] * I.val[j];
            if(aux > 9)
            {
                long long index = i + j;
                div_t myDiv = div(aux, 10);
                aux = myDiv.rem;
                sum[index + 1] += myDiv.quot;
            }
            sum[i + j] += aux;
            while(sum[i + j] > 9)
            {
                long long index = i + j;
                div_t myDiv = div(sum[index], 10);
                sum[index] = myDiv.rem;
                index++;
                sum[index] += myDiv.quot;
            }
        }
    }
    removeLeadingZeros();
    Infinite inf;
    inf.val = sum;
    inf.positive = pos;
    inf.removeLeadingZeros();
    return inf;
}

const bool Infinite::operator==(const Infinite& I) const
{
    if(positive != I.positive)
    {
        return false;
    }
    if(val.size() != I.val.size())
    {
        return false;
    }
    for (long long i = 0; i < val.size(); i++)
    {
        if(val[i] != I.val[i])
        {
            return false;
        }
    }
    return true;
}

const bool Infinite::operator!=(const Infinite& I)  const
{
    if(positive != I.positive)
    {
        return true;
    }
    if(val.size() != I.val.size())
    {
        return true;
    }
    for (long long i = 0; i < val.size(); i++)
    {
        if(val[i] != I.val[i])
        {
            return true;
        }
    }
    return false;
}

const bool Infinite::operator<(const Infinite& I) const
{
    if(positive == I.positive)
    {
        if(val.size() == I.val.size())
        {
            for (long long i = val.size() - 1; i >= 0; i--)
            {
                if(val[i] < I.val[i])
                {
                    return true;
                }
                if(val[i] > I.val[i])
                {
                    return false;
                }
            }
            return false;
        }
        return val.size() < I.val.size() ? positive : !positive;
    }
    return !positive;
}

const bool Infinite::operator>(const Infinite& I) const
{
    if(positive == I.positive)
    {
        if(val.size() == I.val.size())
        {
            for (long long i = val.size() - 1; i >= 0; i--)
            {
                if(val[i] > I.val[i])
                {
                    return true;
                }
                if(val[i] < I.val[i])
                {
                    return false;
                }
            }
            return false;
        }
        return val.size() > I.val.size() ? positive : !positive;
    }
    return positive;
}

const bool Infinite::operator<=(const Infinite& I) const
{
    if(positive == I.positive)
    {
        if(val.size() == I.val.size())
        {
            for (long long i = val.size() - 1; i >= 0; i--)
            {
                if(val[i] < I.val[i])
                {
                    return true;
                }
                if(val[i] > I.val[i])
                {
                    return false;
                }
            }
            return true;
        }
        return val.size() < I.val.size() ? positive : !positive;
    }
    return !positive;
}

const bool Infinite::operator>=(const Infinite& I) const
{
    if(positive == I.positive)
    {
        if(val.size() == I.val.size())
        {
            for (long long i = val.size() - 1; i >= 0; i--)
            {
                if(val[i] > I.val[i])
                {
                    return true;
                }
                if(val[i] < I.val[i])
                {
                    return false;
                }
            }
            return true;
        }
        return val.size() > I.val.size() ? positive : !positive;
    }
    return positive;
}

std::string Infinite::toString() const
{
    std::string str;
    if(positive == false)
    {
        str = "-";
    }
    for (long long i = val.size() - 1; i >= 0; i--)
    {
        str += val[i] + '0';
    }
    return str;
}

template<typename T>
T Infinite::toIntegerType() const
{
    if(*this < std::numeric_limits<T>::min() || *this > std::numeric_limits<T>::max())
    {
        std::cout << "Can't convert.  Min = " << std::numeric_limits<T>::min() << "  Max = " << std::numeric_limits<T>::max() << "   Number = " << this->toString() << std::endl;
        return 0;
    }
    switch (*(typeid(T).name()))
    {
    case 'i':
        return std::stoi(this->toString());
    case 'l':
        return std::stol(this->toString());
    case 'x':
        return std::stoll(this->toString());
    case 'j':
    case 'm':
        return std::stoul(this->toString());
    case 'y':
        return std::stoull(this->toString());
    default:
        std::cout << "Can't convert." << std::endl;
        return 0;
        break;
    }
}

long long Infinite::size() const
{
    return sizeof(int8_t) * val.size() + sizeof(bool);
}

long long Infinite::numberOfDigits() const
{
    return val.size();
}

long long Infinite::maxSize() const
{
    return val.max_size();
}
std::ostream& operator<<(std::ostream& os, const Infinite& inf)
{
    if(!inf.positive)
    {
        os << "-";
    }
    for(long long i = inf.val.size() - 1; i >= 0; i--)
    {
        os << (int)inf.val[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, Infinite& inf)
{
    std::string str;
    is >> str;
    inf.fromString(str);
    return is;
}

#endif /* INFINITE_H */