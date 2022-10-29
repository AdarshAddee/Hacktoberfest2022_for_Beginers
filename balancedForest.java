import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scanner = new Scanner(System.in) ;
        int q = scanner.nextInt() ;
        if (q < 1 || q > 5) {
            throw new IllegalArgumentException("1<=Q<=50000") ;
        }
        while(q>0) {
            int n = scanner.nextInt() ;
            if (n < 1 || n > 50000) {
                throw new IllegalArgumentException("1<=N<=50000") ;
            }
            List<Node> nodes = new ArrayList<Node>(n) ;
			List<GraphNode> graph = new ArrayList<GraphNode>(n) ;
			List<TreeNode> tree = new ArrayList<TreeNode>(n) ;
            for(int i=1;i<=n;i++) {
				Node node = new Node(i,scanner.nextInt()) ;
                nodes.add(node) ;
				graph.add(new GraphNode(node)) ;
				tree.add(new TreeNode(node)) ;
            }
            List<Edge> edges = new ArrayList<Edge>() ;
            for(int i=0;i<n-1;i++) {
                Edge edge = new Edge(scanner.nextInt(), scanner.nextInt()) ;
                edges.add(edge) ;
                addEdge(graph,edge) ;
            }
			graphsToTree(graph.get(0),tree,new HashSet<Node>()) ;
            //System.out.println(tree.get(0)) ;
            //System.out.println(edges) ;
            System.out.println(findMinCw(tree, edges, tree.get(0))) ;
            q-- ;
        }
    }
    
	private static class Node {
		int nodeId ;
        long coins=0 ;
		
		public Node(int nodeId, long coins) {
            this.nodeId = nodeId ;
            this.coins = coins ;
        }
        public int getNodeId() {
            return nodeId ;
        }
        public long getCoins() {
            return coins ;
        }
		
		public boolean equals(Node node) {
            return (node!=null && node.getNodeId() == nodeId) ;
        }
        
        public int hashCode() {
            return nodeId ;
        }
		public String toString() {
			return String.format("nodeId:%s, coins:%d",nodeId,coins) ;
		}
	}
	
	private static class GraphNode {
		
		final Node node ;
		Set<GraphNode> connectedNodes = new HashSet<GraphNode>() ;
		
		public GraphNode(Node node) {
			this.node = node ;
		}
		public Node getNode() {
			return node ;
		}
		public void addConnection(GraphNode addNode) {
			connectedNodes.add(addNode) ;
		}
		public void removeConnection(GraphNode removeNode) {
			connectedNodes.remove(removeNode) ;
		}
		public Set<GraphNode> getConnectedNodes() {
			return connectedNodes ;
		}        
        public String toString() {
			return String.format("Node:%s, connectedNodes[%s]",node.toString(),connectedNodesToString()) ;
        }
		private String connectedNodesToString() {
			StringBuilder builder = new StringBuilder() ;
			for(GraphNode node : connectedNodes) {
				builder.append("Node:").append(node).append(",") ;
			}
			return builder.toString() ;
		}
    }
	
	private static class TreeNode {
		final Node node ;
		TreeNode parentNode ;
		Set<TreeNode> childNodes = new HashSet<TreeNode>() ;
		long totalCoins ;
		
		public TreeNode(Node node) {
			this.node = node ;
			totalCoins = node.getCoins() ;
		}
		public Node getNode() {
			return node ;
		}
		public long getTotalCoins() {
			return totalCoins ;
		}
		public Set<TreeNode> getChildNodes() {
			return childNodes ;
		}
		
		public void setParent(TreeNode node) {
            if(parentNode!=null && node!=null){
                throw new RuntimeException("Multiple parent is not supported. parent:"+parentNode+" current:"+this+" new parent:"+node);
            }
            parentNode = node ;
        }
		
		public void addChildNode(TreeNode node) {
            childNodes.add(node) ;
            totalCoins+=node.getTotalCoins() ;
            node.setParent(this) ;
            if (parentNode!=null) {
                parentNode.addChildCoins(node.getTotalCoins()) ;
            }
        }
		
		public void addChildCoins(long childCoins) {
            totalCoins += childCoins ;
            if (parentNode!=null) {
                parentNode.addChildCoins(childCoins) ;
            }
        }
		
		public void removeChildNode(TreeNode node) {
            childNodes.remove(node) ;
            totalCoins-=node.getTotalCoins() ;
            node.setParent(null) ;
            if (parentNode!=null) {
                parentNode.removeChildCoins(node.getTotalCoins()) ;
            }
        }
		
		public void removeChildCoins(long childCoins) {
            totalCoins -= childCoins ;
            if (parentNode!=null) {
                parentNode.removeChildCoins(childCoins) ;
            }
        }
		
		public boolean isParentOf(TreeNode childNode) {
			return childNodes.contains(childNode) ;
		}
		
		public boolean isRoot() {
			return parentNode == null ;
		}
		
		public String toString() {
			return String.format("Node:%s, totalCoins:%d, parentNode:%s, childNodes:[%s]",node.toString(), totalCoins, 
				(parentNode!=null)?parentNode.getNode().toString():"NULL",childNodes.toString()) ;
		}
	}
	
    private static class Edge {
        int node1 ;
        int node2 ;
        
        public Edge(int node1, int node2) {
			this.node1 = node1 ;
			this.node2 = node2 ;
        }

		public int getNode1() {
			return node1 ;
		}

		public int getNode2() {
			return node2 ;
		}
        
		public void swapNode() {
			int tmpNode = node1 ;
			node1 = node2 ;
			node2 = tmpNode ;
		}
		
        public String toString() {
            return "node1:"+node1+" node2:"+node2 ;
        }
    }
    
    private static void addEdge(List<GraphNode> nodes, Edge edge) {
        nodes.get(edge.getNode1()-1).addConnection(nodes.get(edge.getNode2()-1)) ;
        nodes.get(edge.getNode2()-1).addConnection(nodes.get(edge.getNode1()-1)) ;
    }
    
    private static void removeEdge(List<GraphNode> nodes, Edge edge) {
        nodes.get(edge.getNode1()-1).removeConnection(nodes.get(edge.getNode2()-1)) ;
        nodes.get(edge.getNode2()-1).removeConnection(nodes.get(edge.getNode1()-1)) ;
    }
	
	private static void graphsToTree(GraphNode graph, List<TreeNode> treeNodes, Set<Node> visitedNode) {
		TreeNode treeNode = treeNodes.get(graph.getNode().getNodeId()-1) ;
		visitedNode.add(graph.getNode()) ;
		for(GraphNode connectedNode : graph.getConnectedNodes()) {
			if (!visitedNode.contains(connectedNode.getNode())) {
				treeNode.addChildNode(treeNodes.get(connectedNode.getNode().getNodeId()-1)) ;
				visitedNode.add(connectedNode.getNode()) ;
				graphsToTree(connectedNode, treeNodes, visitedNode) ;
			}			
		}
	}
	
	private static TreeNode removeTreeEdge(List<TreeNode> nodes, Edge edge) {
		TreeNode node1 = nodes.get(edge.getNode1()-1) ;
		TreeNode node2 = nodes.get(edge.getNode2()-1) ;
		
		if (node1.isParentOf(node2)) {
			// node1 is parent of node2
			node1.removeChildNode(node2) ;			
			return node2 ;
		} else {
			node2.removeChildNode(node1) ;
			edge.swapNode() ;
			return node1 ;
		}
	}
	
	private static void addTreeEdge(List<TreeNode> nodes, Edge edge, TreeNode rootNode) {
		TreeNode node1 = nodes.get(edge.getNode1()-1) ;
		TreeNode node2 = nodes.get(edge.getNode2()-1) ;
		
		node1.addChildNode(node2) ;	
	}
	
	//DFS on subTree with expected value
	private static boolean findSubTreeWithValue(TreeNode searchRoot, TreeNode tree, long expectedValue) {
		if (searchRoot.getTotalCoins() <= expectedValue || tree.getTotalCoins() <= expectedValue) {
			return false ;
		}
		for(TreeNode subTree : tree.getChildNodes()) {
			long subTreeCoins = subTree.getTotalCoins() ;
			long remainingCoins = searchRoot.getTotalCoins()-subTreeCoins ;
			
			if (subTreeCoins == expectedValue || remainingCoins==expectedValue) {
				return true ;
			}
			if (findSubTreeWithValue(searchRoot,subTree,expectedValue)) {
				return true ;
			}
		}
		return false ;
	}
	
	public static long findMinCw(List<TreeNode> nodes, List<Edge> edges, TreeNode rootNode) {
        long minCw = -1 ;
        for (int i = 0; i<edges.size() ;i++) {
			Edge removeEdge1 = edges.get(i) ;
			TreeNode tree1 = removeTreeEdge(nodes,removeEdge1) ;
            
            long nodes1Coins = rootNode.getTotalCoins() ;
            long nodes2Coins = tree1.getTotalCoins()  ;

            long largeSetCoins, smallSetCoins ;
            TreeNode treeToSplit = null ;
			
            if (nodes1Coins == nodes2Coins) {
                long cw = nodes1Coins ;
                if (minCw <0 || cw < minCw) {
                    minCw = cw ;
                }
				addTreeEdge(nodes, removeEdge1, rootNode);
                continue ;
            } else if (nodes1Coins>nodes2Coins) {
                largeSetCoins = nodes1Coins ;
                smallSetCoins = nodes2Coins ;
				treeToSplit = rootNode ;
            } else {
                largeSetCoins = nodes2Coins ;
                smallSetCoins = nodes1Coins ;                
				treeToSplit = tree1 ;
            }

            long expectedCw = -1 ;
            long expectedCw1 = -1 ;
			long searchValue ;
            if (largeSetCoins%2 == 0) {
                expectedCw1 = largeSetCoins/2l - smallSetCoins ;
            }
            long expectedCw2 = smallSetCoins - (largeSetCoins - smallSetCoins) ;

            if (expectedCw1 >= 0 && expectedCw2 >=0) {
                expectedCw = Math.min(expectedCw1,expectedCw2) ;
            } else if (expectedCw1 >= 0) {
                expectedCw = expectedCw1 ;
            } else if (expectedCw2 >= 0) {
                expectedCw = expectedCw2 ;
            }
            
            if (expectedCw<0 || (minCw >0 && expectedCw > minCw)) {
                addTreeEdge(nodes, removeEdge1, rootNode);
                continue ;
            }

			if (expectedCw == expectedCw1) {
				searchValue = largeSetCoins/2l ;
			} else {
				searchValue = smallSetCoins ;
			}

			if (findSubTreeWithValue(treeToSplit, treeToSplit, searchValue)) {
				if (minCw <0 || expectedCw < minCw) {
                    minCw = expectedCw ;
                }
			}
		
            addTreeEdge(nodes, removeEdge1, rootNode);
        }
        return minCw ;
    }

}
