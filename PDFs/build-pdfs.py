#!/usr/bin/env python
# -*-coding:utf-8 -*
"""
Build all of my latex handouts and possibly other pdf files.

Uses a tex template files and calls them repeatedly with different inputed file names.
"""
# import pynotify
import subprocess
import os
#import sys
#import time

template_files = ["CM-handouts-4pp",
                  "CM-handouts-6pp"
                 ]

pdf_files = ["../CM0/CM0-Intro.pdf"
            ,"../CM1/CM1-structures.pdf"
            ,"../CM2/CM2-listes.pdf"
            ,"../CM3/CM3-malloc.pdf"
            ,"../CM4/CM4-recursivité.pdf"
            ,"../CM5/CM5-fichiers.pdf"
            ,"../CM6/CM6-Listes_variantes.pdf"
            ,"../CM7/CM7-arbres.pdf"
            ]

#pdf_ending = "handouts-6pp"
pdf_ending = ["handouts-4pp"
             ,"handouts-6pp"
             ]

def compile_pdfs(templates=template_files, pdfs=pdf_files):
    FNULL = open(os.devnull, 'w')
    count_t = 0
    for tmplt in templates:
        count_t+=1
        print ("****************************************")
        print ("TEMPLATE " + str(count_t) + ": " + tmplt)
        print ("****************************************")

        count = 0
        for pdf in pdfs:
            count+=1
            print ('JOB '+ str(count) + ': pdflatex ' + tmplt + ' ' + pdf);
            ret = subprocess.call("pdflatex -interaction=nonstopmode -shell-escape " + " " + tmplt+".tex" + " " +  pdf, shell=True, stdout=FNULL, stderr=subprocess.STDOUT)
            if ret != 0:
                if ret < 0:
                    print ("       Killed by signal", -ret)
                else:
                    print ("       FAILED, exit code ", ret)
            else:
                    #print ("SUCCESS!!!")
                    f = getFileName(pdf)
                    renamePDF(tmplt, f, pdf_ending[count_t-1])
                    print("       Copying original " + pdf);
                    subprocess.call("cp -uav " + pdf + " .", shell=True)
        print ("")

def cleanup(templates=template_files):
    for tmplt in templates:
        print ("Cleaning up temp files for "+tmplt+ "...")
        subprocess.call("rm " + tmplt + ".log", shell=True)
        subprocess.call("rm " + tmplt + ".aux", shell=True)

def getFileName(pdf_name):
    file_name = (os.path.splitext(os.path.basename(pdf_name))[0])
    #print ("Filename: " + file_name)
    return file_name
    #print (os.path.basename(pdf_name))
    #print (os.path.splitext(pdf_name)[1])

def renamePDF(source, dest, ending):
    cmd = "mv " + source+".pdf "  +   dest+"-"+ending   + ".pdf"
    print ("       Moving file: "+cmd)
    subprocess.call(cmd , shell=True)

"""
MAIN
"""

#compile_pdfs(templates[0],pdf_files)
compile_pdfs()
#print ("")
cleanup()

#print ("The end...")
