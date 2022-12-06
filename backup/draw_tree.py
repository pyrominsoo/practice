import turtle
import atexit
import io
import sys
from collections import defaultdict # default dict used as a map, to store node-value mapping.

# Node Class:
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
# Tree Class
class Tree:
    def __init__(self):
        self.root = None
        self.map_nodes = defaultdict(Node)
    def Insert(self,parent, child,dir):
        if self.root is None:
            root_node = Node(parent)
            child_node = Node(child)
            if dir == 'L':
                root_node.left = child_node
            else:
                root_node.right = child_node
            self.root = root_node
            self.map_nodes[parent] = root_node
            self.map_nodes[child] = child_node
            return
        parent_node = self.map_nodes[parent]
        child_node = Node(child)
        self.map_nodes[child] = child_node
        if dir == 'L':
            parent_node.left = child_node
        else:
            parent_node.right = child_node
        return




class TreeDraw(turtle.Turtle):
    """"""
 
    def __init__(self):
        """Turtle Constructor"""
        turtle.Turtle.__init__(self, shape="turtle")
        screen = turtle.Screen()
        screen.bgcolor("lightgrey")
        turtle.tracer(0,0)
        self.pensize(3)
        self.root_x = 0
        self.root_y = 200
        self.node_radius = 50
        self.gap_x = 150
        self.gap_y = 150
        self.line_adj_x = 0
        self.line_adj_y = self.node_radius * 2
        self.txt_off_x = -10
        self.txt_off_y = 40
        self.cir_color = "black"
        self.txt_color = "black"
        self.line_color = "black"
 
    def drawCircle(self, x, y, color, radius=50):
        """
        Moves the turtle to the correct position and draws a circle
        """
        self.penup()
        self.setposition(x, y)
        self.pendown()
        self.color(color)
        self.circle(radius)

    def drawTree(self, tree):
        root_node = tree.root;
        if root_node:
            queue = [(root_node,(self.root_x,self.root_y))]

            while queue:
                node,(pos_x,pos_y) = queue.pop(0)
                self.drawCircle(pos_x,pos_y,self.cir_color,self.node_radius)
                self.drawText(pos_x,pos_y,self.txt_color,node.data)
                if (node.left):
                    child_x = pos_x - self.gap_x
                    child_y = pos_y - self.gap_y
                    self.drawEdge(pos_x,pos_y,child_x,child_y,self.line_color)
                    queue.append((node.left,(child_x,child_y)))
                if (node.right):
                    child_x = pos_x + self.gap_x
                    child_y = pos_y - self.gap_y
                    self.drawEdge(pos_x,pos_y,child_x,child_y,self.line_color)
                    queue.append((node.right,(child_x,child_y)))

    def drawEdge(self, p_x, p_y, c_x, c_y, color):
        new_y = c_y + self.line_adj_y
        if (p_x > c_x):
            new_x = c_x + self.line_adj_x
        else:
            new_x = c_x - self.line_adj_x
        self.drawLine(p_x,p_y,new_x,new_y, color)

    def drawLine(self, x, y, t_x, t_y, color):
        self.penup()
        self.setposition(x,y)
        self.pendown()
        self.color(color)
        self.goto(t_x,t_y)
 
    def drawOlympicSymbol(self):
        """
        Iterates over a set of positions to draw the Olympics logo
        """
        positions = [(0, 0, "blue"), (-120, 0, "purple"), (60,60, "red"),
                     (-60, 60, "yellow"), (-180, 60, "green")]
        for x, y, color in positions:
            self.drawCircle(x, y, color)
 
        self.drawText()
 
    def drawText(self, x, y, color, text):
        """
        Draw text to the screen
        """
        self.penup()
        self.setposition(x + self.txt_off_x, y + self.txt_off_y)
        self.setheading(0)
        self.pendown()
        self.color(color)
        self.write(text, font=("Arial", 16, "bold"))

 
if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        n = int(input())  # number of nodes in tree
        a = raw_input().strip().split()
        # construct the tree according to given list
        tree = Tree()
        i = 0
        while (i < len(a)):
            parent = int(a[i])
            child = int(a[i + 1])
            dir = a[i + 2]
            i += 3
            tree.Insert(parent, child, dir)  # Insert the nodes in tree.
        treedraw = TreeDraw()
        treedraw.drawTree(tree)
        turtle.hideturtle()
        turtle.update()
        turtle.mainloop()
