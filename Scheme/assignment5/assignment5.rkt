#|
CSE 240
ASSIGNMENT 5
DEVEN PILE
4/30/20
|#




;Expressions

(define run1 (lambda ()
               ( + 3 ( - 5 7))
                )
  )

(define run2 (lambda ()
               ( - ( * ( + 8 5 4) 2) 25)
               )
  )


(define run3 (lambda ()
               ( - 10 ( + ( * 3 5) ( + ( * 0 5) 2)))
               )
  )

(define run4 (lambda()
               ( * 5 ( + 4 (/ ( + ( + 10 10) ( * 5 8)) (+ 10 2))))
               )
  )


(define run5 (lambda()
             ( + ( / ( - ( / ( / (* (+ 3 5) (+ 6 4)) 2) 2) 5) 3) ( +( / (+ ( * 2 10) (* 5 4)) 2) ( * 4 5)))
             )
  )


;Multiplication



#|
Part A
Checks if either of the two numbers passed are 0

|#
(define either-zero? (lambda (a b)
                       (or (eq? a 0) (eq? b 0))
                       )
  )
#|
Part B
Checks if two numbers have the same sign

|#

(define same-sign? (lambda (a b)
                     (or ( and (positive? a) (positive? b)) (and (negative? a) (negative? b)))
                     )
  )
#|
Part C
Multiplies two numbers and makes the result positive

|#
(define pos-result-multiply (lambda (a b)
                              (if (eq? (abs b) 1)
                                  (abs a)
                                  (+ (abs a) (pos-result-multiply a ( - (abs b) 1)))
                                  )
                              )
  )
#|
Part D
Mulitplies two numbers and makes the result negative

|#
(define neg-result-multiply (lambda (a b)
                              ( -(pos-result-multiply (abs a) (abs b)))
                              )
  )

#|
Part E
Multiplies two numbers using recursion
|#
(define recursive-multiply(lambda (a b)
                            (cond ((either-zero? a b) (* a 0))
                                  ((same-sign? a b) (pos-result-multiply a b))
                                  (else (neg-result-multiply a b))
                                  )
                            )
  )
                                                      




                            
#|
Part F
Read and Multiply
--Reads two integers from the user and multiplies them

|#
(define readAndMult (lambda()
                      (let
                          ((a (read))
                           (b (read)))
                        (if (and (integer? a) (integer? b))
                            (recursive-multiply a b)
                            (display "Input should be numbers")
                            )
                        )
                      )
  )




;Sum Number List

#|
Part A
Checks if the passed list contains only numbers

|#
(define number-list? (lambda (list)
                       (if (eq? list '())
                           #t
                           (if (number? (car list))
                               (number-list? (cdr list))
                               #f
                               )
                           )
                       )
  )


;Part B




;Summs all the values in a list

(define sum-list (lambda(list)
                   (if (null? list)
                       0
                       ( + (car list) (sum-list (cdr list)))
                       )
                   )
  )
                  
                      
#|
Essentially an interface function, checks if the list passed has only numbers
and then sums all the values in the list together

|#

(define sum-num-list (lambda(list)
                       (if (number-list? list)
                           (sum-list list)
                           #f
                           )
                       )
  )


                            
(display "************************************")
(newline)
(display "Testing run functions")
(newline)
(display "(run1) - answer should be 1 - tested: ")
(run1)
(display "(run2) - answer should be 9 - tested: ")
(run2)
(display "(run3) - answer should be -7 - tested: ")
(run3)
(display "(run4) - answer should be 45 - tested: ")
(run4)
(display "(run5) - answer should be 45 - tested: ")
(run5)

(newline)
(display "Testing multiply helpers")
(newline)
(display "(either-zero? 0 0) - expected #t - got: ")
(either-zero? 0 0)
(display "(either-zero? 1 0) - expected #t - got: ")
(either-zero? 1 0)
(display "(either-zero? 1 1) - expected #f - got: ")
(either-zero? 1 1)
(newline)
(display "(same-sign?  1  1) - expected #t - got: ")
(same-sign? 1 1)
(display "(same-sign? -1  1) - expected #f - got: ")
(same-sign? -1 1)
(display "(same-sign? -1 -1) - expected #t - got: ")
(same-sign? -1 -1)
(newline)
(display "(pos-result-multiply 3 7) - expected 21 - got: ")
(pos-result-multiply 3 7)
(display "(neg-result-multiply 3 7) - expected -21 - got: ")
(neg-result-multiply 3 7)
(newline)
(display "Testing recursive-multiply")
(newline)
(display "(recursive-multiply 6 2) - expected 12 - got: ")
(recursive-multiply 6 2)
(display "(recursive-multiply -6 -2) - expected 12 - got: ")
(recursive-multiply -6 -2)
(display "(recursive-multiply 6 -2) - expected -12 - got: ")
(recursive-multiply 6 -2)
(display "(recursive-multiply -6 2) - expected -12 - got: ")
(recursive-multiply -6 2)
(newline)
(display "Testing ReadAndMult")
(display "Input 6 5 -->")
(ReadAndMult)
(display "30 <-- correct answer")
(newline)

(display "Testing number-list?")(newline)
(display "(number-list? ‘(1 2 3 4)   - epxected #t - got: ")
(number-list? '(1 2 3 4))
(display "(number-list? ‘(1 2 (3) 4) - expected #f - got: ")
(number-list? '(1 2 (3) 4))
(display "(number-list? ‘(1 2 a 4)   - expected #f - got: ")
(number-list? '(1 2 a 4))

(newline)
(display "Testing sum-num-list")(newline)
(display "(sum-num-list '(1 2 3 4 5) - expected 15 - got: ")
(sum-num-list '(1 2 3 4 5))
(display "(sum-num-list '(1 (2)))    - expected #f - got: ")
(sum-num-list '(1 (2)))
(display "(sum-num-list '(a b c))    - expected #f - got: ")
(sum-num-list '(a b c))

(newline)(newline)
;(display "EXTRA CREDIT TESTS*****")
;(newline)
;(display "Testing read-int-list")(newline)
;(display "Input 1 2 3 4 5 q --> ")
;(read-int-list)
;(display "Testing (sum-numlist (read-int-list)")(newline)
;(display "Input 1 2 3 4 5 q --> ")
;(sum-num-list (read-int-list))
;(display "15 <-- expected")
;(newline)
;(newline)
;(display " o(^▽^)o HAPPY NUMBER TEST o(;△;)o ")
;(newline)
;(display "Is 863 happy? (happy? 863) - expected: #t - got: ")
;(happy? 863)
;(display "Is 55562 happy? (happy? 55562) - expected #f - got: ")
;(happy? 55562)
                  
                        

                                                            
                              
  
                              
                          









