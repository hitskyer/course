package com.ht.algorithm.SingleLinkedList;

public class MyException extends Exception {

    public String errorMessage;

    public MyException(String errorMessage){
        super(errorMessage);
        this.errorMessage = errorMessage;
    }

    @Override
    public String getMessage() {
        return errorMessage;
    }
}
