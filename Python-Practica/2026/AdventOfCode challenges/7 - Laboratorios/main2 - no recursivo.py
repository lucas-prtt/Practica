file = open("./7 - Laboratorios/puzzle-input.txt")
#file = open("./7 - Laboratorios/test.txt")
linesList = file.readlines()
class Ray:
    def __init__(self, strength : int, location : int):
        self.strength = strength # Strength = En cuantas timelines el rayo esta alli
        self.location = location
    def addStrength(self, s : int):
        self.strength += s
    def __repr__(self):
        return "(Ray: S="+str(self.strength) + " - L=" + str(self.location)+")"


def getRayIn(rays : list, location : int) -> Ray:
    try:
        item = next(filter( lambda x : x.location == location, rays))
    except StopIteration:
        return None
    return item

def sendRay(rays : list, baseRay : Ray, location : int):
    existingRay = getRayIn(rays, location)
    if(existingRay == None):
        rays.append(Ray(baseRay.strength, location))
    else:
        existingRay.addStrength(baseRay.strength)

def propagate(baseRays:list, line:str):
    rays = []

    for i, c in enumerate(list(line)):
        match c:
            case "S":
                rays.append(Ray(1, i))
            case "^":
                ray = getRayIn(baseRays, i)
                if(ray != None):
                    sendRay(rays, ray, i+1)
                    sendRay(rays, ray, i-1)
                pass
            case ".":
                ray = getRayIn(baseRays, i)
                if(ray != None):
                    sendRay(rays, ray, i)
                pass
            case _:
                pass
    return rays

rays = []
for line in linesList:
    rays = propagate(rays, line)
    #print(line, rays)    

timeLines = sum(map(lambda r : r.strength, rays))
print(timeLines)
