from django.shortcuts import render
from django.http import HttpResponse
#重定向url
from django.urls import reverse
from django.http import HttpResponseRedirect


# Create your views here.
def add(request):
    a = request.GET['a']
    b = request.GET['b']
    c  = int(a) + int(b)
    return HttpResponse(str(c))

def add2(request,a,b):
    c = int(a) + int(b)
    return HttpResponse(str(c))

def old_to_new_add(request,a,b):
    return HttpResponseRedirect(
        reverse('add2',args=(a,b))
    )

def index(request):
    return render(request,'home.html')

